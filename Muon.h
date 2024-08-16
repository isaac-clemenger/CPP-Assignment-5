// PHYS 30762 Programming in C++
// Assignment 5
// Isaac Clemeneger 17/04/2024
// Header for muon class, contains member variables: muon_number, is_isolated, as well as variables of particle class

#ifndef MUON_H
#define MUON_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"Particle.h"

// Define constants
const double muon_rest_mass{105.7}; // In MeV

class Muon: public Particle
{
  private:
    int muon_number;
    bool is_isolated;
  public:
    // Default constructor
    Muon() :
      Particle{}, muon_number{}, is_isolated{} {rest_mass = muon_rest_mass;}
    // Parameterised constructor
    Muon(int particle_charge, int particle_muon_number, bool particle_is_isolated, Four_momentum particle_four_momentum);
    
    // Copy constructor
    Muon(const Muon &original);

    // Move constructor
    Muon(Muon&& original);

    // Overload Assignment operator for deep copying
    Muon& operator=(Muon& original);

    // Move assignment
    Muon& operator=(Muon&& original);
    
    // Destructor
    ~Muon(){}

    // Getters
    int get_muon_number() const {return muon_number;}
    bool get_is_isolated() const {return is_isolated;}

    // Setters
    void set_muon_number(const int particle_muon_number) {muon_number = particle_muon_number;}
    void set_is_isolated(const bool particle_is_isolated) {is_isolated = particle_is_isolated;}

    // Function to switch particle to antiparticle (or vice-versa)
    void switch_to_anti() override;

    // Print function
    void print_particle_data() const override;
};  

#endif
