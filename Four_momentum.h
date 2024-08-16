// PHYS 30762 Programming in C++
// Assignment 5
// Isaac Clemeneger 17/04/2024
// Header for four momentum class, contains variables: energy, px, py, pz 

#ifndef FOUR_MOMENTUM_H
#define FOUR_MOMENTUM_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

class Four_momentum
{
  private:
     double energy, px, py, pz;
  public:
    // Default constructor
    Four_momentum()
    {std::cout<<"Default constructor called\n";}

    // Parameterised Constructor
    Four_momentum(double energy, double px, double py, double pz);

    // Copy constructor
    Four_momentum(const Four_momentum &original);

    // Move constructor
    Four_momentum(Four_momentum&& original);

    // Overload Assignment operator for deep copying
    Four_momentum& operator=(Four_momentum& original);
  
    // Overload Assignment operator to move objects 
    Four_momentum& operator=(Four_momentum&& original);

    // Getters
    double get_energy() const {return energy;}
    double get_px() const {return px;}
    double get_py() const {return py;}
    double get_pz() const {return pz;}

    // Setters
    void set_energy(const double particle_energy) {energy = check_energy(particle_energy);}
    void set_px(const double particle_px) {px = particle_px;}
    void set_py(const double particle_py) {py = particle_py;}
    void set_pz(const double particle_pz) {pz = particle_pz;}
    
    // Validate input
    double check_energy(double energy);

    // Printing function
    void print_four_momentum();
};

#endif