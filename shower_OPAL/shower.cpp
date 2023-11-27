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
pythia.readString("StringZ:aLund = 0.11000");
pythia.readString("StringZ:bLund = 0.52000");
pythia.readString("StringZ:aExtraSQuark = 0.0");
pythia.readString("StringZ:aExtraDiQuark = 0.5");
pythia.readString("StringZ:usePetersonC = on");
pythia.readString("StringZ:usePetersonB = on");
pythia.readString("StringZ:epsilonC = -0.03100");
pythia.readString("StringZ:epsilonB = -0.00200");
pythia.readString("StringPT:sigma = 0.40000");
pythia.readString("StringFlav:probQQtoQ = 0.08500");
pythia.readString("StringFlav:probStoUD = 0.31000");
pythia.readString("StringFlav:probSQtoQQ = 0.45000");
pythia.readString("StringFlav:probQQ1toQQ0 = 0.02500");
pythia.readString("StringFlav:mesonUDvector = 0.60000");
pythia.readString("StringFlav:mesonSvector = 0.40000");
pythia.readString("StringFlav:mesonCvector = 0.72000");
pythia.readString("StringFlav:mesonBvector = 0.72000");
pythia.readString("StringFlav:mesonUDL1S0J1 = 0.43000");
pythia.readString("StringFlav:mesonUDL1S1J0 = 0.08000");
pythia.readString("StringFlav:mesonUDL1S1J1 = 0.08000");
pythia.readString("StringFlav:mesonUDL1S1J2 = 0.17000");
pythia.readString("StringFlav:suppressLeadingB = on");
pythia.readString("StringFlav:lightLeadingBSup = 1.0");
pythia.readString("StringFlav:heavyLeadingBSup = 1.0");
pythia.readString("StringFlav:etaPrimeSup = 0.40");
pythia.readString("TimeShower:pTmin = 0.95");
pythia.readString("TimeShower:pTminChgQ = 0.95");
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
