// PHYS 30762 Programming in C++
// Assignment 5
// Isaac Clemeneger 17/04/2024
// Header for particle class, contains variables: type, mass, charge, spin, four momentum for any particle

#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>
#include"Four_momentum.h"

// Define constants
const double speed_of_light_in_vacuo{2.99792458e8};

class Particle
{
protected:
  int charge;
  double rest_mass;
  const float spin{0.5};
  std::unique_ptr<Four_momentum> four_momentum; // Unique pointer such that the p of each particle is different
public:
  // Default constructor
  Particle()
    {std::cout<<"Default constructor called\n";}
  // Parameterised constructor
  Particle(int particle_charge, double particle_rest_mass, Four_momentum particle_four_momentum);
  // Destructor
  virtual ~Particle()
  {
    std::cout<<"Calling destructor\n";
  }

  // Copy constructor
  Particle(const Particle &original);

  // Move constructor
  Particle(Particle&& original);

  // Overload Assignment operator for deep copying
  Particle& operator=(Particle& original);

  // Overload Assignment operator to move objects 
  Particle& operator=(Particle&& original);

  // Getter functions (accessors) to:
  int get_charge() const {return charge;}
  double get_rest_mass() const {return rest_mass;}
  Four_momentum get_four_momentum() const {return *four_momentum;}

  // Setter functions, to change value of data members
  void set_charge(const int particle_charge) {charge = particle_charge;}
  void set_rest_mass(const double particle_rest_mass) {rest_mass = particle_rest_mass;}
  void set_four_momentum(const Four_momentum particle_four_momentum) {four_momentum = std::make_unique<Four_momentum>(particle_four_momentum);}

  // Friend functions to manipulate four momenta of particles
  friend Four_momentum sum_four_momenta(const Particle& particle_1, const Particle& particle_2);
  friend double dot_four_momenta(const Particle& particle_1, const Particle& particle_2);

  // Function to charge particles to antiparticles
  virtual void switch_to_anti();

  // Function to print info about a particle
  virtual void print_particle_data() const;
};

#endif