#include "Pythia8/Pythia.h"
#include "Pythia8Plugins/HepMC2.h"

using namespace Pythia8;

int main(int argc, char* argv[]) {

if(argc!=3) {
  cout<<"Usage: ./shower [input_file] [output_file]"<<endl;
  cout<<"input_file -- LHE format"<<endl;
  cout<<"output_file -- HepMC format"<<endl;
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
pythia.readString("PartonLevel:MPI = off");
pythia.readString("HadronLevel:Hadronize = on");
//pythia.readString("13:mayDecay = off");
//pythia.readString("211:mayDecay = off");
//pythia.readString("321:mayDecay = off");
//pythia.readString("130:mayDecay = off");
//pythia.readString("2112:mayDecay = off");
//pythia.readString("Random:setSeed = on");
//pythia.readString("Random:seed = 1");
pythia.readString(inf);
pythia.init();

//Allow for possibility of a few faulty events.
int nAbort = 30;
int iAbort = 0;

//Begin event loop; generate until none left in input file.
for(int iEvent = 0; ; ++iEvent) {
  if (!pythia.next()) {
    if(pythia.info.atEndOfFile()) break; //Exit event loop because reaching the end of file.
    if(++iAbort < nAbort) continue;//First few failures are "acceptable".
    break;
  }
  //Convert the Pythia event to HepMC event.
  HepMC::GenEvent* hepmcevt = new HepMC::GenEvent();
  ToHepMC.fill_next_event(pythia, hepmcevt);
  ascii_io<<hepmcevt;
  delete hepmcevt;
}//End of event loop.
return 0;
}//end of main
