// PHYS 30762 Programming in C++
// Assignment 5
// Isaac Clemeneger 17/04/2024
// File containing member functions, constructors and overloaded operators of the electron class
#include<iostream>
#include"Electron.h"
#include"Particle.h"
#include"Four_momentum.h"

// Constructors
// Parameterised constructor
Electron::Electron(int particle_charge, int particle_electron_number, Four_momentum particle_four_momentum,
double em_1, double em_2, double had_1, double had_2) :
Particle{particle_charge, electron_rest_mass, particle_four_momentum}, electron_number{particle_electron_number} 
{
  set_calorimeter_deposits(em_1, em_2, had_1, had_2);
}

// Copy constructor
Electron::Electron(const Electron &original) :
Particle(original)
{
  std::cout<<"Calling electron copy constructor\n";  
  electron_number = original.electron_number;
  calorimeter_deposits = original.calorimeter_deposits;  
}

// Move constructor
Electron::Electron(Electron&& original) :
Particle(std::move(original))
{
  std::cout <<"Calling electron move constructor\n";  
  electron_number = original.electron_number;
  original.electron_number = 0;

  calorimeter_deposits = original.calorimeter_deposits;
  original.calorimeter_deposits = std::vector<double>{0,0,0,0};
}

// Overload Assignment operator for deep copying
Electron& Electron::operator=(Electron& original)
{

  std::cout <<"Electron copy assignment\n";
  if(&original == this) return *this; // no self assignment
  Particle::operator=(original);
  electron_number = original.electron_number;
  calorimeter_deposits = original.calorimeter_deposits;  
  return *this;
}

// Move assignment
Electron& Electron::operator=(Electron&& original)
{
  std::cout <<"Electron move assignment\n";
  if(&original == this) return *this;
  Particle::operator=(std::move(original));

  electron_number = original.electron_number;
  original.electron_number = 0;

  calorimeter_deposits = original.calorimeter_deposits;
  original.calorimeter_deposits = std::vector<double>{0,0,0,0};  

  return *this;    
}

// Function to check calorimeter deposits
std::vector<double> Electron::check_calorimeter_deposits(const double em_1, const double em_2, const double had_1, const double had_2)
{
  // Find the sum of the particles deposits
  double sum_deposits{em_1 + em_2 + had_1 + had_2};

  // Ensure this is smaller than particle's energy, if so throw an error
  if (sum_deposits > four_momentum->get_energy())
  {
    std::cout<<"Calorimeter deposits > electron's energy! This violates energy conservation\n";
    throw sum_deposits;     
  }
  else
  {
    std::vector<double> particle_calorimeter_deposits{em_1, em_2, had_1, had_2};
    return particle_calorimeter_deposits;
  }
}

// Function to switch particle to antiparticle (or vice-versa)
void Electron::switch_to_anti() 
{
  charge = charge * -1;
  electron_number = electron_number * -1;   
}

// Print function
void Electron::print_particle_data() const 
{
  std::cout<<"Electron: [m,q,s,Le,(calorimeter deposits)] = ["<<rest_mass<<", "<<charge<<", "<<spin<<", "<<electron_number<<", ("<<calorimeter_deposits[0]<<", "<<calorimeter_deposits[1]<<", "<<calorimeter_deposits[2]<<", "<<calorimeter_deposits[3]<<")]\n"; 
  std::cout<<"The electron's four momentum is: ";
  four_momentum->print_four_momentum(); 
}