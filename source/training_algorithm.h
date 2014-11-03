/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   T R A I N I N G   A L G O R I T H M   C L A S S   H E A D E R                                              */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __TRAININGALGORITHM_H__
#define __TRAININGALGORITHM_H__

// System includes

#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <limits>
#include <cmath>
#include <ctime>

// OpenNN includes

#include "performance_functional.h"

// TinyXml includes

#include "../tinyxml2/tinyxml2.h"

namespace OpenNN
{

/// This abstract class represents the concept of training algorithm for a neural network. 
/// Any derived class must implement the perform_training(void) method.

class TrainingAlgorithm
{

public:

   // DEFAULT CONSTRUCTOR

   explicit TrainingAlgorithm(void);

   // GENERAL CONSTRUCTOR

   explicit TrainingAlgorithm(PerformanceFunctional*);

   // XML CONSTRUCTOR

   explicit TrainingAlgorithm(const tinyxml2::XMLDocument&);

   // DESTRUCTOR

   virtual ~TrainingAlgorithm(void);

    // ASSIGNMENT OPERATOR

    virtual TrainingAlgorithm& operator = (const TrainingAlgorithm&);

    // EQUAL TO OPERATOR

    virtual bool operator == (const TrainingAlgorithm&) const;


   // STRUCTURES

   ///
   /// This structure contains the training algorithm results. 
   ///

   struct Results
   {
      /// Returns a string representation of the results structure. 

      virtual std::string to_string(void) const
      {
         std::string str;

         return(str);
      }

       /// Returns a default (empty) string matrix with the final results from training.

       virtual Matrix<std::string> write_final_results(const unsigned&) const
       {
          Matrix<std::string> final_results;         

          return(final_results);
       }
   };

   // METHODS

   // Get methods

   PerformanceFunctional* get_performance_functional_pointer(void) const;

   bool has_performance_functional(void) const;

   // Utilities

   const bool& get_display(void) const;
  
   // Set methods

   void set(void);
   void set(PerformanceFunctional*);
   virtual void set_default(void);

   virtual void set_performance_functional_pointer(PerformanceFunctional*);

   void set_display(const bool&);

   // Training methods

   virtual void check(void) const;

   /// Trains a neural network which has a performance functional associated. 

   virtual Results* perform_training(void) = 0;

   virtual std::string write_training_algorithm_type(void) const;

   // Serialization methods

   virtual std::string to_string(void) const;
   void print(void) const;

   virtual Matrix<std::string> to_string_matrix(void) const;

   virtual tinyxml2::XMLDocument* to_XML(void) const;
   virtual void from_XML(const tinyxml2::XMLDocument&);

   void save(const std::string&) const;
   void load(const std::string&);

   virtual void initialize_random(void);

protected:

   // FIELDS

   /// Pointer to a performance functional for a multilayer perceptron object.

   PerformanceFunctional* performance_functional_pointer;

   // UTILITIES

   /// Display messages to screen.

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

