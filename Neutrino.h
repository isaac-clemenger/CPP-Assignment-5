// PHYS 30762 Programming in C++
// Assignment 5
// Isaac Clemeneger 17/04/2024
// Header for neutrino class, contains member variables: flavour, has_interacted, as well as variables of particle class

#ifndef NEUTRINO_H
#define NEUTRINO_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"Particle.h"

class Neutrino: public Particle
{
  private:
    std::string flavour;
    bool has_interacted;  
  public:
    // Default constructor
    Neutrino() :
      Particle{}, flavour{}, has_interacted{} {rest_mass = 0; charge = 0;}
    // Parameterised constructor
    Neutrino(std::string particle_flavour, bool particle_has_interacted, Four_momentum particle_four_momentum);  
    
    // Copy constructor
    Neutrino(const Neutrino &original);

    // Move constructor
    Neutrino(Neutrino&& original);

    // Overload Assignment operator for deep copying
    Neutrino& operator=(Neutrino& original);

    // Move assignment
    Neutrino& operator=(Neutrino&& original);
    
    // Deconstructor
    ~Neutrino(){}

    // Getters
    std::string get_flavour() const {return flavour;}
    bool get_has_interacted() const {return has_interacted;}

    // Setters
    void set_flavour(const std::string particle_flavour) {flavour = particle_flavour;}
    void set_has_interacted(const bool particle_has_interacted) {has_interacted = particle_has_interacted;}

    // Function to switch particle to antiparticle (or vice-versa)
    void switch_to_anti() override;

    // Print function
    void print_particle_data() const override;
};

#endif