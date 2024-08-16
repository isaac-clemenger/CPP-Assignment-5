// PHYS 30762 Programming in C++
// Assignment 5
// Isaac Clemeneger 17/04/2024
// File containing member functions, constructors and overloaded operators of the four momentum class

#include<iostream>
#include"Four_momentum.h"

// Function that ensures the velocity is physical
double Four_momentum::check_energy(double energy)
{
  if (energy < 0)
  { 
    std::cout<<"This energy is non physical\n";
    // Throw so we can catch it in the try catch function in the main
    throw energy;
  } 
  else 
  {
    return energy;
  } 
}

// Parameterised Constructor
Four_momentum::Four_momentum(double energy, double px, double py, double pz)
{
  set_energy(energy);
  set_px(px); 
  set_py(py);
  set_pz(pz); 
}

// Copy constructor
Four_momentum::Four_momentum(const Four_momentum &original)
{
  std::cout<<"Calling copy constructor\n";
  energy = original.energy;
  px = original.px;
  py = original.py;
  pz = original.pz;
}

// Move constructor
Four_momentum::Four_momentum(Four_momentum&& original)
{
  std::cout <<"Calling move constructor\n";
  energy = original.energy;
  original.energy = 0;
  
  px = original.px;
  original.px = 0;

  py = original.py;
  original.py = 0;

  pz = original.pz; 
  original.pz = 0; 
}

// Overload Assignment operator for deep copying
Four_momentum& Four_momentum::operator=(Four_momentum& original)
{
  std::cout <<"Copy assignment\n";
  if(&original == this) return *this; // no self assignment
  energy = original.energy;
  px = original.px;
  py = original.py;
  pz = original.pz;
  return *this;
}
  
// Overload Assignment operator to move objects 
Four_momentum& Four_momentum::operator=(Four_momentum&& original)
{
  std::cout <<"Move assignment\n";
  if(&original == this) return *this; // no self assignment
  
  energy = original.energy;
  original.energy = 0;
  
  px = original.px;
  original.px = 0;

  py = original.py;
  original.py = 0;

  pz = original.pz; 
  original.pz = 0;
  return *this; // Return the same object, which now contains the moved values  
}


// Printing function
void Four_momentum::print_four_momentum()
{
  std::cout<<"Four momentum [E/c,px,py,pz] = ["<<energy<<", "<<px<<", "<<py<<", "<<pz<<"]\n";
}