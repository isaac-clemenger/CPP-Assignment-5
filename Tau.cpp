// PHYS 30762 Programming in C++
// Assignment 5
// Isaac Clemeneger 17/04/2024
// File containing member functions, constructors and overloaded operators of the tau class

#include<iostream>
#include"Tau.h"
#include"Particle.h"
#include"Four_momentum.h"

// Constructors
// Parameterised constructor
Tau::Tau(int particle_charge, int particle_tau_number, std::string particle_decay_type, std::string particle_lepton_decay_type, Four_momentum particle_four_momentum) :
Particle{particle_charge, tau_rest_mass, particle_four_momentum}, tau_number{particle_tau_number},
decay_type{particle_decay_type}, lepton_decay_type{particle_lepton_decay_type} 
{
  // Make the decay products
  create_decay_products();
}

// Copy constructor
Tau::Tau(const Tau &original) :
Particle(original)
{
  std::cout<<"Calling tau copy constructor\n";  
  tau_number = original.tau_number;
  decay_type = original.decay_type;
  lepton_decay_type = original.lepton_decay_type;  
  // Need to take more care for decay products as is a vector of pointers
  for (int i{}; i < (original.decay_products).size(); i++)
  {
    decay_products[i] = std::make_unique<Particle>(*(original.decay_products[i]));
  }
}

// Move constructor
Tau::Tau(Tau&& original) :
Particle(std::move(original))
{
  std::cout <<"Calling tau move constructor\n";  
  tau_number = original.tau_number;
  original.tau_number = 0;

  decay_type = original.decay_type;
  original.decay_type = "";

  lepton_decay_type = original.lepton_decay_type;
  original.lepton_decay_type = ""; 

  // Need to take more care for decay products as is a vector of pointers
  for (int i{}; i < (original.decay_products).size(); i++)
  {
    decay_products.push_back(std::move(original.decay_products[i]));
    original.decay_products[i] = nullptr;
  }
}

// Overload Assignment operator for deep copying
Tau& Tau::operator=(Tau& original)
{

  std::cout <<"Tau copy assignment\n";
  if(&original == this) return *this; // no self assignment
  Particle::operator=(original);
  tau_number = original.tau_number;
  decay_type = original.decay_type;
  lepton_decay_type = original.lepton_decay_type;  
  // Need to take more care for decay products as is a vector of pointers
  for (int i{}; i < (original.decay_products).size(); i++)
  {
    decay_products[i] = std::make_unique<Particle>(*(original.decay_products[i]));
  }
  return *this;
}

// Move assignment
Tau& Tau::operator=(Tau&& original)
{
  std::cout <<"Tau move assignment\n";
  if(&original == this) return *this;
  Particle::operator=(std::move(original));
  tau_number = original.tau_number;
  original.tau_number = 0;

  decay_type = original.decay_type;
  original.decay_type = "";

  lepton_decay_type = original.lepton_decay_type;
  original.lepton_decay_type = ""; 

  // Need to take more care for decay products as is a vector of pointers
  for (int i{}; i < (original.decay_products).size(); i++)
  {
    decay_products.push_back(std::move(original.decay_products[i]));
    original.decay_products[i] = nullptr;
  } 
  return *this;    
}

// Function to switch particle to antiparticle (or vice-versa)
void Tau::switch_to_anti() 
{
  charge = charge * -1;
  tau_number = tau_number * -1;   
}

// Function to create decay products
void Tau::create_decay_products()
{
  // Only create decay products if decay is leptonic (for this assignment)
  if (decay_type == "leptonic")
    {
    // Antitau neutrino is always created, so initialise this first
    decay_products.push_back(std::make_unique<Neutrino>(Neutrino("antitau", 1, Four_momentum(1,2,3,4))));
    // Now need to choose if electrons or muons are produced, decays specified when creating onject
    if (lepton_decay_type == "electron")
    {
      decay_products.push_back(std::make_unique<Neutrino>(Neutrino("antielectron", 1, Four_momentum(1,2,3,4))));
      decay_products.push_back(std::make_unique<Electron>(Electron(-1, 1, Four_momentum(1000,20,993,74), 12, 34, 56, 21)));
    }
    else if (lepton_decay_type == "muon")
    {
      decay_products.push_back(std::make_unique<Neutrino>(Neutrino("antimuon", 1, Four_momentum(1,2,3,4))));
      decay_products.push_back(std::make_unique<Muon>(Muon(-1, 1, 1, Four_momentum(1,2,3,4))));
    }
  }
  // Need to ammend decay products based on whether we have tau or antitau
  if (charge == 1)
  {
    for(auto decay_it(decay_products.begin()); decay_it < decay_products.end(); decay_it++)
    {
      (*decay_it) -> switch_to_anti();
    } 
  }
}

// Print function
void Tau::print_particle_data() const 
{
  std::cout<<"Tau: [m,q,s,Lt,decay type] = ["<<rest_mass<<", "<<charge<<", "<<spin<<", "<<tau_number<<", "<<decay_type<<"]\n";  
  std::cout<<"The tau's four momentum is: ";
  four_momentum->print_four_momentum(); 
  std::cout<<"Decay products: \n";
  for(auto decay_it(decay_products.begin()); decay_it < decay_products.end(); decay_it++)
  {
    (*decay_it) -> print_particle_data();  
  }
}