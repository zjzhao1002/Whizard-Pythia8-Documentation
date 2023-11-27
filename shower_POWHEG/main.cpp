#include "Pythia8/Pythia.h"
#include "Pythia8Plugins/HepMC2.h"
#include "Pythia8Plugins/PowhegHooks.h"

using namespace Pythia8;

int main(int argc, char* argv[]) {

if(argc!=3) {
  cout<<"Usage: ./main [input_file] [output_file]"<<endl;
  cout<<"input_file -- LHE format"<<endl;
  cout<<"output_file -- HepMC2 format"<<endl;
  return 0;
}

string instr="Beams:LHEF = ";
string inf;

inf=instr+argv[1];

//Interface for conversion from Pythia8::Event to HepMC event.
HepMC::Pythia8ToHepMC ToHepMC; 

//Specify file where HepMC events will be stored.
HepMC::IO_GenEvent ascii_io(argv[2], std::ios::out);

//Generator
Pythia pythia;

//Initialize LHEF run.
pythia.readString("Beams:frameType = 4");
pythia.readString(inf);

//Read configuration file
pythia.readFile("pythia8_input.cmnd");

//Allow for possibility of a few faulty events
int nAbort = 30;
int iAbort = 0;

//Read in key POWHEG merging settings
int vetoMode = pythia.settings.mode("POWHEG:veto");
int MPIvetoMode = pythia.settings.mode("POWHEG:MPIveto");
bool loadHooks = (vetoMode>0 || MPIvetoMode>0);

//Add in user hooks for shower vetoing
shared_ptr<PowhegHooks> powhegHooks;
if (loadHooks) {
  //Set ISR and FSR to start at the kinematical limit
  if(vetoMode>0) {
    pythia.readString("SpaceShower:pTmaxMatch = 2");
    pythia.readString("TimeShower:pTmaxMatch = 2");
  }
  //Set MPI to start at the kinematical limit
  if(MPIvetoMode>0) {
    pythia.readString("MultipartonInteractions:pTmaxMatch = 2");
  }
  powhegHooks = make_shared<PowhegHooks>();
  pythia.setUserHooksPtr((UserHooksPtr) powhegHooks);
}

//Initialise and list settings
pythia.init();

unsigned long int nISRveto = 0, nFSRveto = 0;

//Begin event loops; generate until none left in input file
for(int iEvent=0; ; ++iEvent) {
  if(!pythia.next()) {
    if(pythia.info.atEndOfFile()) break; //Exit event loop because reaching the end of file.
    if(++iAbort < nAbort) continue;
    break;
  }

  //Update ISR/FSR veto counters
  if(loadHooks) {
    nISRveto += powhegHooks->getNISRveto();
    nFSRveto += powhegHooks->getNFSRveto();
  }
  //Convert the Pythia event to HepMC event.
  HepMC::GenEvent* hepmcevt = new HepMC::GenEvent();
  ToHepMC.fill_next_event(pythia, hepmcevt);
  ascii_io<<hepmcevt;
  delete hepmcevt;
}//end of event loop
cout<<"Number of ISR emissions vetoed: "<<nISRveto<<endl;
cout<<"Number of FSR emissions vetoed: "<<nFSRveto<<endl;
return 0;
}//end of main
