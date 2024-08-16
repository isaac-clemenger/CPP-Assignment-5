// PHYS 30762 Programming in C++
// Assignment 5
// Isaac Clemeneger 17/04/2024
// Header for electron class, contains member variables: electron_number, calorimeter_deposits, as well as variables of particle class

#ifndef ELECTRON_H
#define ELECTRON_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"Particle.h"

// Define constants
const double electron_rest_mass{0.511}; // In MeV

class Electron: public Particle
{
  private:
    int electron_number;
    std::vector<double> calorimeter_deposits{std::vector<double>(4)}; //Initialise as vector size 4
  public:
    // Default constructor
    Electron() :
      Particle{}, electron_number{}, calorimeter_deposits{} {rest_mass = electron_rest_mass;}
    // Parameterised constructor
    Electron(int particle_charge, int particle_electron_number, Four_momentum particle_four_momentum,
    double em_1, double em_2, double had_1, double had_2);

    // Copy constructor
    Electron(const Electron &original);

    // Move constructor
    Electron(Electron&& original);

    // Overload Assignment operator for deep copying
    Electron& operator=(Electron& original);

    // Move assignment
    Electron& operator=(Electron&& original);

    // Destructor
    ~Electron(){}

    // Getters
    int get_electron_number() const {return electron_number;}

    // Setter
    void set_electron_number(const int particle_electron_number) {electron_number = particle_electron_number;}
    void set_calorimeter_deposits(const double em_1, const double em_2, const double had_1, const double had_2)
    {
      calorimeter_deposits = check_calorimeter_deposits(em_1, em_2, had_1, had_2);
    }

    // Function to check calorimeter deposits
    std::vector<double> check_calorimeter_deposits(const double em_1, const double em_2, const double had_1, const double had_2);

    // Function to switch particle to antiparticle (or vice-versa)
    void switch_to_anti() override; 

    // Print function
    void print_particle_data() const override;
};

#endif