// PHYS 30762 Programming in C++
// Assignment 5
// Isaac Clemeneger 17/04/2024
// File containing member functions, constructors and overloaded operators of the neutrino class

#include<iostream>
#include"Neutrino.h"
#include"Particle.h"
#include"Four_momentum.h"

// Constructors 
// Parameterised constructor
Neutrino::Neutrino(std::string particle_flavour, bool particle_has_interacted, Four_momentum particle_four_momentum) :
Particle{0, 0, particle_four_momentum}, flavour{particle_flavour}, has_interacted{particle_has_interacted} {}

// Copy constructor
Neutrino::Neutrino(const Neutrino &original) :
Particle(original)
{
  std::cout<<"Calling neutrino copy constructor\n";  
  flavour = original.flavour;
  has_interacted = original.has_interacted;  
}

// Move constructor
Neutrino::Neutrino(Neutrino&& original) :
Particle(std::move(original))
{
  std::cout <<"Calling neutrino move constructor\n";  
  flavour = original.flavour;
  original.flavour = "";

  has_interacted = original.has_interacted;
  original.has_interacted = 0; 
}

// Overload Assignment operator for deep copying
Neutrino& Neutrino::operator=(Neutrino& original)
{

  std::cout <<"Neutrino copy assignment\n";
  if(&original == this) return *this; // no self assignment
  Particle::operator=(original);
  flavour = original.flavour;
  has_interacted = original.has_interacted;  
  return *this;
}

// Move assignment
Neutrino& Neutrino::operator=(Neutrino&& original)
{
  std::cout <<"Neutrino move assignment\n";
  if(&original == this) return *this;
  Particle::operator=(std::move(original));
  
  flavour = original.flavour;
  original.flavour = "";

  has_interacted = original.has_interacted;
  original.has_interacted = 0; 
  return *this;    
}


// Function to switch particle to antiparticle (or vice-versa)
void Neutrino::switch_to_anti() 
{
  if (flavour.substr(0,4) == "anti")
  {
    flavour = flavour.substr(4);
  }
  else
  {
    flavour = "anti" + flavour;
  }
} 


// Print function
void Neutrino::print_particle_data() const 
{
  std::cout<<"Neutrino: [flavour,m,q,s,interacted?] = ["<<flavour<<", "<<rest_mass<<", "<<charge<<", "<<spin<<", "<<has_interacted<<"]\n";  
  std::cout<<"The neutrino's four momentum is: ";
  four_momentum->print_four_momentum(); 
}