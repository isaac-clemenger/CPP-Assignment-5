// PHYS 30762 Programming in C++
// Assignment 5
// Isaac Clemeneger 17/04/2024
// File containing member functions, constructors and overloaded operators of the particle class

#include<iostream>
#include"Particle.h"
#include"Four_momentum.h"

// Memeber functions
// Function that makes particles antiparticles
void Particle::switch_to_anti()
{
  charge = charge * -1;
}

// Function that prints particle data
void Particle::print_particle_data() const
{
  std::cout<<"Particle: [m,q,s] = ["<<rest_mass<<", "<<charge<<", "<<spin<<"]\n";
  std::cout<<"The particle's four momentum is: ";
  four_momentum->print_four_momentum();
  return;
}

// Constructors
// Parameterised constructor
Particle::Particle(int particle_charge, double particle_rest_mass, Four_momentum particle_four_momentum)
{
  std::cout<<"Calling parameterised constructor\n"; 
  set_charge(particle_charge);
  set_rest_mass(particle_rest_mass);
  set_four_momentum(particle_four_momentum);
} 

// Copy constructor
Particle::Particle(const Particle &original)
{
  std::cout<<"Calling copy constructor\n";
  charge = original.charge;
  rest_mass = original.rest_mass;
  four_momentum = std::make_unique<Four_momentum>(*(original.four_momentum));
}

// Move constructor
Particle::Particle(Particle&& original)
{
  std::cout <<"Calling move constructor\n";

  charge = original.charge;
  original.charge = 0;

  rest_mass = original.rest_mass;
  original.rest_mass = 0;

  four_momentum = std::move(original.four_momentum);
  original.four_momentum = nullptr;
}

// Overloaded operators

// Overload Assignment operator for deep copying
Particle& Particle::operator=(Particle& original)
{
  std::cout <<"Copy assignment\n";
  if(&original == this) return *this; // no self assignment
  four_momentum = nullptr;
  charge = original.charge;
  rest_mass = original.rest_mass;
  four_momentum = std::make_unique<Four_momentum>(*(original.four_momentum));
  return *this; // Return the same object, which now contains the copied values
}  

// Overload Assignment operator to move objects 
Particle& Particle::operator=(Particle&& original)
{
  std::cout <<"Move assignment\n";
  if(&original == this) return *this; // no self assignment

  charge = original.charge;
  original.charge = 0;

  rest_mass = original.rest_mass;
  original.rest_mass = 0;

  four_momentum = std::move(original.four_momentum);
  original.four_momentum = nullptr;
  return *this; // Return the same object, which now contains the moved values
}

// Friend functions to manipulate four momenta of particles
// Summing
Four_momentum sum_four_momenta(const Particle& particle_1, const Particle& particle_2)
{
  Four_momentum four_momentum_p1{particle_1.get_four_momentum()};
  Four_momentum four_momentum_p2{particle_2.get_four_momentum()};
  Four_momentum summed_four_momenta(four_momentum_p1.get_energy() + four_momentum_p2.get_energy(),four_momentum_p1.get_px() + four_momentum_p2.get_px(), four_momentum_p1.get_py() + four_momentum_p2.get_py(), four_momentum_p1.get_pz() + four_momentum_p2.get_pz());
  return summed_four_momenta;
}

// Dot product
double dot_four_momenta(const Particle& particle_1, const Particle& particle_2)
{
  Four_momentum four_momentum_p1{particle_1.get_four_momentum()};
  Four_momentum four_momentum_p2{particle_2.get_four_momentum()};
  double dot_product{four_momentum_p1.get_energy()*four_momentum_p2.get_energy() - (four_momentum_p1.get_px()*four_momentum_p2.get_px() + four_momentum_p1.get_py()*four_momentum_p2.get_py() + four_momentum_p1.get_pz()*four_momentum_p2.get_pz())};  
  return dot_product;
}