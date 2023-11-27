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
pythia.readString("StringZ:aLund = 0.40000");
pythia.readString("StringZ:bLund = 0.82400");
pythia.readString("StringZ:aExtraSQuark = 0.0");
pythia.readString("StringZ:aExtraDiQuark = 0.5");
pythia.readString("StringZ:usePetersonC = on");
pythia.readString("StringZ:usePetersonB = on");
pythia.readString("StringZ:epsilonC = 0.04000");
pythia.readString("StringZ:epsilonB = 0.00180");
pythia.readString("StringPT:sigma = 0.36200");
pythia.readString("StringFlav:probQQtoQ = 0.10500");
pythia.readString("StringFlav:probStoUD = 0.28300");
pythia.readString("StringFlav:probSQtoQQ = 0.71000");
pythia.readString("StringFlav:probQQ1toQQ0 = 0.05000");
pythia.readString("StringFlav:mesonUDvector = 0.54000");
pythia.readString("StringFlav:mesonSvector = 0.46000");
pythia.readString("StringFlav:mesonCvector = 0.65000");
pythia.readString("StringFlav:mesonBvector = 0.65000");
pythia.readString("StringFlav:mesonUDL1S0J1 = 0.12000");
pythia.readString("StringFlav:mesonUDL1S1J0 = 0.04000");
pythia.readString("StringFlav:mesonUDL1S1J1 = 0.12000");
pythia.readString("StringFlav:mesonUDL1S1J2 = 0.20000");
pythia.readString("StringFlav:suppressLeadingB = on");
pythia.readString("StringFlav:lightLeadingBSup = 0.58");
pythia.readString("StringFlav:heavyLeadingBSup = 0.58");
pythia.readString("StringFlav:etaPrimeSup = 0.27");
pythia.readString("TimeShower:pTmin = 0.735");
pythia.readString("TimeShower:pTminChgQ = 0.735");
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
