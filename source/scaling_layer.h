/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   S C A L I N G   L A Y E R   C L A S S   H E A D E R                                                        */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __SCALINGLAYER_H__
#define __SCALINGLAYER_H__

// System includes

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

// OpenNN includes

#include "vector.h"
#include "matrix.h"

// TinyXml includes

#include "../tinyxml2/tinyxml2.h"

namespace OpenNN
{

/// This class represents a layer of scaling neurons.
/// Scaling layers are included in the definition of a neural network. 
/// They are used to normalize variables so they are in an appropriate range for computer processing.  

class ScalingLayer
{

public:

   // DEFAULT CONSTRUCTOR

   explicit ScalingLayer(void);

   // INPUTS NUMBER CONSTRUCTOR

   explicit ScalingLayer(const unsigned&);

   // STATISTICS CONSTRUCTOR

   explicit ScalingLayer(const Vector< Statistics<double> >&);

   // COPY CONSTRUCTOR

   ScalingLayer(const ScalingLayer&);

   // DESTRUCTOR

   virtual ~ScalingLayer(void);

   // ASSIGNMENT OPERATOR

   ScalingLayer& operator = (const ScalingLayer&);

   // EQUAL TO OPERATOR

   bool operator == (const ScalingLayer&) const;

   // ENUMERATIONS

   /// Enumeration of available methods for scaling the input variables.  
   
   enum ScalingMethod{NoScaling, MinimumMaximum, MeanStandardDeviation};

   // GET METHODS

   unsigned get_scaling_neurons_number(void) const;

   // Inputs statistics

   Vector< Statistics<double> > get_statistics(void) const;
   Statistics<double> get_statistics(const unsigned&) const;

   Matrix<double> arrange_statistics(void) const;

   // Variables scaling and unscaling

   const ScalingMethod& get_scaling_method(void) const;

   std::string write_scaling_method(void) const;
   std::string write_scaling_method_text(void) const;

   // Display messages

   const bool& get_display(void) const;

   // SET METHODS

   void set(void);
   void set(const unsigned&);
   void set(const Vector< Statistics<double> >&);
   void set(const tinyxml2::XMLDocument&);
   void set(const ScalingLayer&);

   virtual void set_default(void);

   // Statistics

   void set_statistics(const Vector< Statistics<double> >&);
   void set_item_statistics(const unsigned&, const Statistics<double>&);

   void set_minimum(const unsigned&, const double&);
   void set_maximum(const unsigned&, const double&);
   void set_mean(const unsigned&, const double&);
   void set_standard_deviation(const unsigned&, const double&);

   // Scaling method

   void set_scaling_method(const ScalingMethod&);
   void set_scaling_method(const std::string&);

   // Display messages

   void set_display(const bool&);

   // Pruning and growing

   void prune_scaling_neuron(const unsigned&);

   // Check methods

   bool is_empty(void) const;

   // Inputs scaling function

   void initialize_random(void);

   void check_range(const Vector<double>&) const;

   Vector<double> calculate_outputs(const Vector<double>&) const;
   Vector<double> calculate_derivatives(const Vector<double>&) const;
   Vector<double> calculate_second_derivatives(const Vector<double>&) const;

   Vector<double> calculate_minimum_maximum_outputs(const Vector<double>&) const;
   Vector<double> calculate_minimum_maximum_derivatives(const Vector<double>&) const;
   Vector<double> calculate_minimum_maximum_second_derivatives(const Vector<double>&) const;

   Vector<double> calculate_mean_standard_deviation_outputs(const Vector<double>&) const;
   Vector<double> calculate_mean_standard_deviation_derivatives(const Vector<double>&) const;
   Vector<double> calculate_mean_standard_deviation_second_derivatives(const Vector<double>&) const;

   Matrix<double> arrange_Jacobian(const Vector<double>&) const;
   Vector< Matrix<double> > arrange_Hessian_form(const Vector<double>&) const;

   // Expression methods

   std::string write_no_scaling_expression(const Vector<std::string>&, const Vector<std::string>&) const;

   std::string write_minimum_maximum_expression(const Vector<std::string>&, const Vector<std::string>&) const;

   std::string write_mean_standard_deviation_expression(const Vector<std::string>&, const Vector<std::string>&) const;

   std::string write_expression(const Vector<std::string>&, const Vector<std::string>&) const;

   // Serialization methods

   std::string to_string(void) const;

   tinyxml2::XMLDocument* to_XML(void) const;
   virtual void from_XML(const tinyxml2::XMLDocument&);

protected:

   // MEMBERS

   /// Statistics of input variables.

   Vector< Statistics<double> > statistics;

   /// Method for scaling the input variables.

   ScalingMethod scaling_method;

   /// Display warning messages to screen. 

   bool display;
};

}

#endif


// OpenNN: Open Neural Networks Library.
// Neural Designer Copyright © 2013 Roberto López and Ismael Santana (Intelnics)
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
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

