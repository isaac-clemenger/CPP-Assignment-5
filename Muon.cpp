// PHYS 30762 Programming in C++
// Assignment 5
// Isaac Clemeneger 17/04/2024
// File containing member functions, constructors and overloaded operators of the muon class
#include<iostream>
#include"Muon.h"
#include"Particle.h"
#include"Four_momentum.h"

// Constructors
// Parameterised constructor
Muon::Muon(int particle_charge, int particle_muon_number, bool particle_is_isolated, Four_momentum particle_four_momentum) :
Particle{particle_charge, muon_rest_mass, particle_four_momentum}, muon_number{particle_muon_number},
is_isolated{particle_is_isolated} {}

// Copy constructor
Muon::Muon(const Muon &original) :
Particle(original)
{
  std::cout<<"Calling muon copy constructor\n";  
  muon_number = original.muon_number;
  is_isolated = original.is_isolated;  
}

// Move constructor
Muon::Muon(Muon&& original) :
Particle(std::move(original))
{
  std::cout <<"Calling muon move constructor\n";  
  muon_number = original.muon_number;
  original.muon_number = 0;
  
  is_isolated = original.is_isolated;
  original.is_isolated = 0;
}

// Overload Assignment operator for deep copying
Muon& Muon::operator=(Muon& original)
{

  std::cout <<"Muon copy assignment\n";
  if(&original == this) return *this; // no self assignment
  Particle::operator=(original);
  muon_number = original.muon_number;
  is_isolated = original.is_isolated;  
  return *this;
}

// Move assignment
Muon& Muon::operator=(Muon&& original)
{
  std::cout <<"Muon move assignment\n";
  if(&original == this) return *this;
  Particle::operator=(std::move(original));
  
  muon_number = original.muon_number;
  original.muon_number = 0;
  
  is_isolated = original.is_isolated;
  original.is_isolated = 0;
  return *this;    
}

// Function to switch particle to antiparticle (or vice-versa)
void Muon::switch_to_anti() 
{
  charge = charge * -1;
  muon_number = muon_number * -1;   
}

// Print function
void Muon::print_particle_data() const 
{
  std::cout<<"Muon: [m,q,s,Lmu,isolated?] = ["<<rest_mass<<", "<<charge<<", "<<spin<<", "<<muon_number<<", "<<is_isolated<<"]\n";  
  std::cout<<"The muon's four momentum is: ";
  four_momentum->print_four_momentum(); 
}