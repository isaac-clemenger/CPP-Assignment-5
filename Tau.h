// PHYS 30762 Programming in C++
// Assignment 5
// Isaac Clemeneger 17/04/2024
// Header for tau class, contains member variables: tau_number, decay_type, lepton_decay_type, decay_products, as well as variables of particle class

#ifndef TAU_H
#define TAU_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"Particle.h"
#include"Electron.h"
#include"Muon.h"
#include"Neutrino.h"

// Define constants
const double tau_rest_mass{1777}; // In MeV

class Tau: public Particle
{
  private:
    int tau_number;
    std::string decay_type;
    std::string lepton_decay_type;
    std::vector<std::unique_ptr<Particle>> decay_products;
  public:
    // Default constructor
    Tau() :
      Particle{}, tau_number{}, decay_type{} {rest_mass = tau_rest_mass;}  
    // Parameterised constructor
    Tau(int particle_charge, int particle_tau_number, std::string particle_decay_type, std::string particle_lepton_decay_type, Four_momentum particle_four_momentum);
    
    // Copy constructor
    Tau(const Tau &original);

    // Move constructor
    Tau(Tau&& original);

    // Overload Assignment operator for deep copying
    Tau& operator=(Tau& original);

    // Move assignment
    Tau& operator=(Tau&& original);
    // Destructor
    ~Tau(){}

    // Getters
    int get_tau_number() const {return tau_number;}
    std::string get_decay_type() const {return decay_type;}

    // Setters
    void set_tau_number(const int particle_tau_number) {tau_number = particle_tau_number;}
    void set_decay_type(const std::string particle_decay_type) {decay_type = particle_decay_type;}

    // Function to switch particle to antiparticle (or vice-versa)
    void switch_to_anti() override;

    // Function to create decay products
    void create_decay_products();  

    // Print function
    void print_particle_data() const override;
};

#endif