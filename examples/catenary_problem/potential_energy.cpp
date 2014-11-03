/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   P O T E N T I A L   E N E R G Y   C L A S S                                                                */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */ 
/*                                                                                                              */
/****************************************************************************************************************/

// System includes

#include <string>
#include <sstream>
#include <iostream>     
#include <fstream>     
#include <cmath>     

// OpenNN includes

#include "../../source/opennn.h"

// Examples includes

#include "potential_energy.h"


namespace OpenNN
{

// GENERAL CONSTRUCTOR

PotentialEnergy::PotentialEnergy(void) : OrdinaryDifferentialEquations()
{
   set_default();
}


// DESTRUCTOR

PotentialEnergy::~PotentialEnergy(void) 
{
}


// METHODS

// void set_default(void) method

void PotentialEnergy::set_default(void)
{
   independent_variables_number = 1;
   dependent_variables_number = 1;

   solution_method = RungeKuttaFehlberg;

   points_number = 1001;

   tolerance = 1.0e-6;

   initial_size = (unsigned int)1.0e3;
   warning_size = (unsigned int)1.0e6;
   error_size = (unsigned int)1.0e9;

   initial_independent_variable = 0;
   final_independent_variable = 1;

   initial_dependent_variables.set(1, 0.0);

   display = true;
}


// Vector<double> calculate_dependent_variables_dots(const NeuralNetwork&, const Vector<double>&) const method

Vector<double> PotentialEnergy::calculate_dependent_variables_dots(const NeuralNetwork& neural_network, const Vector<double>& variables) const
{
   const double x = variables[0];

   const Vector<double> inputs(1, x);
   
   const Vector<double> outputs = neural_network.calculate_outputs(inputs);

   const double y = outputs[0];

   const Matrix<double> Jacobian = neural_network.calculate_Jacobian(inputs);

   const double dydx = Jacobian[0][0];

   const Vector<double> dependent_variables_dots(1, y*sqrt(1.0 + pow(dydx,2)));

   return(dependent_variables_dots);
}

}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2012 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the s of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
