// PHYS 30762 Programming in C++
// Assignment 5
// Isaac Clemeneger 17/04/2024
// Practice inheritance in C++ classes
/*
Program demonstrates inheritance in the context of a particle catalogue, which covers all lepton particles. The base class contains
basic information such as mass, charge, spin, as well as a pointer to a four momentum object. In the second inheritance tier, there are
classes for: electrons, muons, taus, neutrinos. Each class has specific member vairables. The tau object has a fucntionality where it 
will decay into the relevant leptons, as only the decay products of taus are detected in particle detectors. In main, print functionalities
are demonstrated, as well as summing and taking the dot product of the four momenta for two particles, via friend fucntions. The move
constructor is also demonstrated, as well as the function of shared pointers.  
*/

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>
#include"Particle.h"
#include"Four_momentum.h"
#include"Electron.h"
#include"Muon.h"
#include"Tau.h"
#include"Neutrino.h"

// Main program
int main()
{
  try
  {
    // Shared pointers such that they can be copied into the vector, so that we can use the initial objects created later in the program
    std::shared_ptr<Electron> electron1{std::make_shared<Electron>(Electron(-1, 1, Four_momentum(1000,10,10,100), 120, 34, 56, 21))};
    std::shared_ptr<Electron> electron2{std::make_shared<Electron>(Electron(-1, 1, Four_momentum(2000,20,20,200), 102, 4, 19, 78))};
    std::shared_ptr<Electron> positron1{std::make_shared<Electron>(Electron(1, -1, Four_momentum(1000,10,10,100), 102, 4, 19, 78))};

    std::shared_ptr<Muon> muon1{std::make_shared<Muon>(Muon(-1,1,0,Four_momentum(1000,10,10,100)))};
    std::shared_ptr<Muon> muon2{std::make_shared<Muon>(Muon(-1,1,1,Four_momentum(2000,20,20,200)))};
    std::shared_ptr<Muon> muon3{std::make_shared<Muon>(Muon(-1,1,1,Four_momentum(3000,30,30,300)))};
    std::shared_ptr<Muon> muon4{std::make_shared<Muon>(Muon(-1,1,0,Four_momentum(4000,40,40,400)))};
    std::shared_ptr<Muon> antimuon1{std::make_shared<Muon>(Muon(1,-1,1,Four_momentum(1000,10,10,100)))};
    
    std::shared_ptr<Neutrino> electron_neutrino1{std::make_shared<Neutrino>(Neutrino("electron", 0, Four_momentum(1000,10,10,100)))};
    std::shared_ptr<Neutrino> muon_neutrino1{std::make_shared<Neutrino>(Neutrino("muon", 1, Four_momentum(1000,10,10,100)))};
    
    std::shared_ptr<Tau> tau1{std::make_shared<Tau>(Tau(-1, 1, "leptonic", "muon", Four_momentum(1000,10,10,100)))};
    std::shared_ptr<Tau> antitau1{std::make_shared<Tau>(Tau(1, -1, "leptonic", "electron", Four_momentum(1000,10,10,100)))};

    std::vector<std::shared_ptr<Particle>> particles;
    particles.push_back(electron1);
    particles.push_back(electron2);
    particles.push_back(positron1);

    particles.push_back(muon1);
    particles.push_back(muon2);
    particles.push_back(muon3);
    particles.push_back(muon4);
    particles.push_back(antimuon1);

    particles.push_back(electron_neutrino1);
    particles.push_back(muon_neutrino1);

    particles.push_back(tau1);
    particles.push_back(antitau1);

    for (auto particles_it(particles.begin()); particles_it < particles.end(); particles_it++)
    {
      (*particles_it) -> print_particle_data();
    }

    // Demonstrate summing four momenta
    Four_momentum sum{sum_four_momenta(*electron1, *electron2)};
    std::cout<<"The sum of the four momenta of electrons 1 and 2 is: ";
    sum.print_four_momentum();

    // Demonstrate dot product of the four momenta
    std::cout<<"The dot product of the four momenta of the positron and antimuon is: "<<dot_four_momenta(*positron1, *antimuon1)<<"\n";
    
    // Demnstrate move assignment
    std::unique_ptr<Electron> electron_pointer{std::make_unique<Electron>(Electron(-1, 1, Four_momentum(1000,20,993,74), 102, 69, 77, 33))};
    Electron new_electron{};
    new_electron = std::move(*electron_pointer);
    new_electron.print_particle_data();

    // Create a shared pointer of a tau that is owned by multiple variables
    std::shared_ptr<Tau> tau_shared{std::make_shared<Tau>(Tau(-1, 1, "leptonic", "muon", Four_momentum(1000,10,10,100)))};
    std::shared_ptr<Tau> tau_detected1 = tau_shared;
    std::shared_ptr<Tau> tau_detected2 = tau_shared;
    std::cout<<"How many pointers own this tau: "<<tau_shared.use_count()<<"\n";
  }
  catch(...)
  {
    // If non physical parameters are inputted, exit the program
    std::cout<<"Exiting program\n";
    return 1;
  }  
  return 0;
}