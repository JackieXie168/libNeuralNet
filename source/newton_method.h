/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   N E W T O N   M E T H O D   C L A S S   H E A D E R                                                        */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __NEWTONMETHOD_H__
#define __NEWTONMETHOD_H__

// System includes

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// OpenNN includes 

#include "performance_functional.h"

#include "training_algorithm.h"
#include "training_rate_algorithm.h"

// TinyXml includes

#include "../tinyxml2/tinyxml2.h"

namespace OpenNN
{

///
/// This concrete class represents the Newton method training algorithm for a performance functional of a neural network.
////

class NewtonMethod : public TrainingAlgorithm
{

public:

   // DEFAULT CONSTRUCTOR

   explicit NewtonMethod(void); 

   // PERFORMANCE FUNCTIONAL CONSTRUCTOR

   explicit NewtonMethod(PerformanceFunctional*);

   // XML CONSTRUCTOR

   explicit NewtonMethod(const tinyxml2::XMLDocument&); 


   // DESTRUCTOR

   virtual ~NewtonMethod(void);


   // STRUCTURES

   ///
   /// This structure contains the training results for the Newton method. 
   ///

   struct NewtonMethodResults : public TrainingAlgorithm::Results
   {
       /// Default constructor.

       NewtonMethodResults(void)
       {
           Newton_method_pointer = NULL;
       }

       /// Newton method constructor.

       NewtonMethodResults(NewtonMethod* new_Newton_method_pointer)
       {
           Newton_method_pointer = new_Newton_method_pointer;
       }

       /// Destructor.

       virtual ~NewtonMethodResults(void)
       {
       }

       /// Pointer to the Newton method object for which the training results are to be stored.

      NewtonMethod* Newton_method_pointer;

      // Training history

      /// History of the neural network parameters over the training iterations. 

      Vector< Vector<double> > parameters_history;

      /// History of the parameters norm over the training iterations. 

      Vector<double> parameters_norm_history;

      /// History of the performance function performance over the training iterations. 

      Vector<double> performance_history;

      /// History of the generalization performance over the training iterations. 

      Vector<double> generalization_performance_history;

      /// History of the performance function gradient over the training iterations. 

      Vector< Vector<double> > gradient_history;

      /// History of the gradient norm over the training iterations. 

      Vector<double> gradient_norm_history;

      /// History of the inverse Hessian over the training iterations. 

      Vector< Matrix<double> > inverse_Hessian_history;

      /// History of the random search training direction over the training iterations. 

      Vector< Vector<double> > training_direction_history;

      /// History of the random search training rate over the training iterations. 

      Vector<double> training_rate_history;

      /// History of the elapsed time over the training iterations. 

      Vector<double> elapsed_time_history;

      // Final values

      /// Final neural network parameters vector. 

      Vector<double> final_parameters;

      /// Final neural network parameters norm. 

      double final_parameters_norm;

      /// Final performance function evaluation.

      double final_performance;

      /// Final generalization performance. 

      double final_generalization_performance;

      /// Final performance function gradient. 

      Vector<double> final_gradient;

      /// Final gradient norm. 

      double final_gradient_norm;

      /// Final Newton method training direction. 

      Vector<double> final_training_direction;

      /// Final Newton method training rate. 

      double final_training_rate;

      /// Elapsed time of the training process. 

      double elapsed_time;

      /// Maximum number of training iterations.

      unsigned iterations_number;

      void resize_training_history(const unsigned&);
      std::string to_string(void) const;

      Matrix<std::string> write_final_results(const unsigned& precision = 3) const;
   };


   // METHODS

   const TrainingRateAlgorithm& get_training_rate_algorithm(void) const;
   TrainingRateAlgorithm* get_training_rate_algorithm_pointer(void);

   // Training parameters

   const double& get_warning_parameters_norm(void) const;
   const double& get_warning_gradient_norm(void) const;
   const double& get_warning_training_rate(void) const;

   const double& get_error_parameters_norm(void) const;
   const double& get_error_gradient_norm(void) const;
   const double& get_error_training_rate(void) const;

   // Stopping criteria

   const double& get_minimum_parameters_increment_norm(void) const;

   const double& get_minimum_performance_increase(void) const;
   const double& get_performance_goal(void) const;
   const double& get_gradient_norm_goal(void) const;
   const unsigned& get_maximum_generalization_performance_decreases(void) const;

   const unsigned& get_maximum_iterations_number(void) const;
   const double& get_maximum_time(void) const;

   // Reserve training history

   const bool& get_reserve_parameters_history(void) const;
   const bool& get_reserve_parameters_norm_history(void) const;

   const bool& get_reserve_performance_history(void) const;
   const bool& get_reserve_gradient_history(void) const;
   const bool& get_reserve_gradient_norm_history(void) const;
   const bool& get_reserve_inverse_Hessian_history(void) const;
   const bool& get_reserve_generalization_performance_history(void) const;

   const bool& get_reserve_training_direction_history(void) const;
   const bool& get_reserve_training_rate_history(void) const;
   const bool& get_reserve_elapsed_time_history(void) const;

   // Utilities

   const unsigned& get_display_period(void) const;

   void set_performance_functional_pointer(PerformanceFunctional*);

   void set_default(void);

   // Training parameters

   void set_warning_parameters_norm(const double&);
   void set_warning_gradient_norm(const double&);
   void set_warning_training_rate(const double&);

   void set_error_parameters_norm(const double&);
   void set_error_gradient_norm(const double&);
   void set_error_training_rate(const double&);

   // Stopping criteria

   void set_minimum_parameters_increment_norm(const double&);

   void set_minimum_performance_increase(const double&);
   void set_performance_goal(const double&);
   void set_gradient_norm_goal(const double&);
   void set_maximum_generalization_performance_decreases(const unsigned&);

   void set_maximum_iterations_number(const unsigned&);
   void set_maximum_time(const double&);

   // Reserve training history

   void set_reserve_parameters_history(const bool&);
   void set_reserve_parameters_norm_history(const bool&);

   void set_reserve_performance_history(const bool&);
   void set_reserve_gradient_history(const bool&);
   void set_reserve_gradient_norm_history(const bool&);
   void set_reserve_inverse_Hessian_history(const bool&);
   void set_reserve_generalization_performance_history(const bool&);

   void set_reserve_training_direction_history(const bool&);
   void set_reserve_training_rate_history(const bool&);
   void set_reserve_elapsed_time_history(const bool&);

   /// Makes the training history of all variables to be reseved or not in memory.

   void set_reserve_all_training_history(const bool&);

   // Utilities

   void set_display_period(const unsigned&);

   // Training methods

   Vector<double> calculate_gradient_descent_training_direction(const Vector<double>&) const;
   Vector<double> calculate_training_direction(const Vector<double>&, const Matrix<double>&) const;

   NewtonMethodResults* perform_training(void);

   std::string write_training_algorithm_type(void) const;

   // Serialization methods

   Matrix<std::string> to_string_matrix(void) const;

   tinyxml2::XMLDocument* to_XML(void) const;
   void from_XML(const tinyxml2::XMLDocument&);

private:

   /// Training rate algorithm object.
   /// It is used to calculate the step for the Newton training direction.

   TrainingRateAlgorithm training_rate_algorithm;

   /// Value for the parameters norm at which a warning message is written to the screen. 

   double warning_parameters_norm;

   /// Value for the gradient norm at which a warning message is written to the screen. 

   double warning_gradient_norm;   

   /// Training rate value at wich a warning message is written to the screen.

   double warning_training_rate;

   /// Value for the parameters norm at which the training process is assumed to fail. 
   
   double error_parameters_norm;

   /// Value for the gradient norm at which the training process is assumed to fail. 

   double error_gradient_norm;

   /// Training rate at wich the line minimization algorithm is assumed to be unable to bracket a minimum.

   double error_training_rate;


   // STOPPING CRITERIA

   /// Norm of the parameters increment vector at which training stops.

   double minimum_parameters_increment_norm;

   /// Minimum performance improvement between two successive iterations. It is used as a stopping criterion.

   double minimum_performance_increase;

   /// Goal value for the performance. It is used as a stopping criterion.

   double performance_goal;

   /// Goal value for the norm of the objective function gradient. It is used as a stopping criterion.

   double gradient_norm_goal;

   /// Maximum number of iterations at which the generalization performance decreases.
   /// This is an early stopping method for improving generalization.

   unsigned maximum_generalization_performance_decreases;

   /// Maximum number of iterations to perform_training. It is used as a stopping criterion.

   unsigned maximum_iterations_number;

   /// Maximum training time. It is used as a stopping criterion.

   double maximum_time;

   // TRAINING HISTORY

   /// True if the parameters history matrix is to be reserved, false otherwise.

   bool reserve_parameters_history;

   /// True if the parameters norm history vector is to be reserved, false otherwise.

   bool reserve_parameters_norm_history;

   /// True if the performance history vector is to be reserved, false otherwise.

   bool reserve_performance_history;

   /// True if the gradient history matrix is to be reserved, false otherwise.

   bool reserve_gradient_history;

   /// True if the gradient norm history vector is to be reserved, false otherwise.

   bool reserve_gradient_norm_history;

   /// True if the inverse Hessian history vector of matrices is to be reserved, false otherwise.

   bool reserve_inverse_Hessian_history;

   /// True if the training direction history matrix is to be reserved, false otherwise.
   
   bool reserve_training_direction_history;

   /// True if the training rate history vector is to be reserved, false otherwise.

   bool reserve_training_rate_history;

   /// True if the elapsed time history vector is to be reserved, false otherwise.

   bool reserve_elapsed_time_history;

   /// True if the Generalization performance history vector is to be reserved, false otherwise. 

   bool reserve_generalization_performance_history;

   /// Number of iterations between the training showing progress.

   unsigned display_period;

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

