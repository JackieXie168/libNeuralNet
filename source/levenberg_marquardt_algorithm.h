/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   L E V E N B E R G - M A R Q U A R D T   A L G O R I T H M   C L A S S   H E A D E R                        */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __LEVENBERGMARQUARDTALGORITHM_H__
#define __LEVENBERGMARQUARDTALGORITHM_H__

// System includes

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <limits>
#include <math.h>
#include <time.h>

// OpenNN includes

#include "training_algorithm.h"

#include "linear_algebraic_equations.h"

// TinyXml includes

#include "../tinyxml2/tinyxml2.h"

namespace OpenNN
{

/// This concrete class represents a Levenberg-Marquardt Algorithm training
/// algorithm for the sum squared error performance functional for a multilayer perceptron.

class LevenbergMarquardtAlgorithm : public TrainingAlgorithm
{

public:

   // DEFAULT CONSTRUCTOR

   explicit LevenbergMarquardtAlgorithm(void);

   // PERFORMANCE FUNCTIONAL CONSTRUCTOR

   explicit LevenbergMarquardtAlgorithm(PerformanceFunctional*);

   // XML CONSTRUCTOR

   explicit LevenbergMarquardtAlgorithm(const tinyxml2::XMLDocument&);

   // DESTRUCTOR

   virtual ~LevenbergMarquardtAlgorithm(void);

   // STRUCTURES

   ///
   /// This structure contains the training results for the Levenberg-Marquardt algorithm. 
   ///

   struct LevenbergMarquardtAlgorithmResults : public TrainingAlgorithm::Results
   {
       /// Default constructor.

       LevenbergMarquardtAlgorithmResults(void)
       {
           Levenberg_Marquardt_algorithm_pointer = NULL;
       }

       /// Random search constructor.

       LevenbergMarquardtAlgorithmResults(LevenbergMarquardtAlgorithm* new_Levenberg_Marquardt_algorithm_pointer)
       {
           Levenberg_Marquardt_algorithm_pointer = new_Levenberg_Marquardt_algorithm_pointer;
       }

       /// Destructor.

       virtual ~LevenbergMarquardtAlgorithmResults(void)
       {
       }

       /// Pointer to the Levenberg-Marquardt algorithm object for which the training results are to be stored.

      LevenbergMarquardtAlgorithm* Levenberg_Marquardt_algorithm_pointer;

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

      /// History of the Hessian approximation over the training iterations. 

      Vector< Matrix<double> > Hessian_approximation_history;

      /// History of the damping parameter over the training iterations. 

      Vector<double> damping_parameter_history;

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

      /// Elapsed time of the training process. 

      double elapsed_time;

      /// Maximum number of training iterations.

      unsigned iterations_number;

      void resize_training_history(const unsigned&);
      std::string to_string(void) const;

      Matrix<std::string> write_final_results(const unsigned& precision = 3) const;

   };

   // METHODS

   // Get methods

   // Training parameters

   const double& get_warning_parameters_norm(void) const;
   const double& get_warning_gradient_norm(void) const;

   const double& get_error_parameters_norm(void) const;
   const double& get_error_gradient_norm(void) const;

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
   const bool& get_reserve_Hessian_approximation_history(void) const;
   const bool& get_reserve_generalization_performance_history(void) const;

   const bool& get_reserve_elapsed_time_history(void) const;

   // Utilities

   const unsigned& get_display_period(void) const;

   const double& get_damping_parameter(void) const;

   const double& get_damping_parameter_factor(void) const;

   const double& get_minimum_damping_parameter(void) const;
   const double& get_maximum_damping_parameter(void) const;

   const bool& get_reserve_damping_parameter_history(void) const;

   const Vector<double>& get_damping_parameter_history(void) const;

   // Set methods

   void set_default(void);

   void set_damping_parameter(const double&);

   void set_damping_parameter_factor(const double&);

   void set_minimum_damping_parameter(const double&);
   void set_maximum_damping_parameter(const double&);

   void set_reserve_damping_parameter_history(const bool&);

   // Training parameters

   void set_warning_parameters_norm(const double&);
   void set_warning_gradient_norm(const double&);

   void set_error_parameters_norm(const double&);
   void set_error_gradient_norm(const double&);

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
   void set_reserve_Hessian_approximation_history(const bool&);
   void set_reserve_generalization_performance_history(const bool&);

   void set_reserve_elapsed_time_history(const bool&);

   /// Makes the training history of all variables to be reseved or not in memory.

   virtual void set_reserve_all_training_history(const bool&);

   // Utilities

   void set_display_period(const unsigned&);

   // Training methods

   void check(void) const;

   double calculate_performance(const Vector<double>&) const;
   Vector<double> calculate_gradient(const Vector<double>&, const Matrix<double>&) const;
   Matrix<double> calculate_Hessian_approximation(const Matrix<double>&) const;

   LevenbergMarquardtAlgorithmResults* perform_training(void);

   std::string write_training_algorithm_type(void) const;

   // Serialization methods

   Matrix<std::string> to_string_matrix(void) const;

   tinyxml2::XMLDocument* to_XML(void) const;

   void from_XML(const tinyxml2::XMLDocument&);

private:

   // MEMBERS

   /// Initial Levenberg-Marquardt parameter.

   double damping_parameter;

   /// Minimum Levenberg-Marquardt parameter.

   double minimum_damping_parameter;

   /// Maximum Levenberg-Marquardt parameter.

   double maximum_damping_parameter;

   /// Damping parameter increase/decrease factor.

   double damping_parameter_factor;

   /// True if the damping parameter history vector is to be reserved, false otherwise.  

   bool reserve_damping_parameter_history;

   /// Vector containing the damping parameter history over the training iterations.

   Vector<double> damping_parameter_history;


   /// Value for the parameters norm at which a warning message is written to the screen. 

   double warning_parameters_norm;

   /// Value for the gradient norm at which a warning message is written to the screen. 

   double warning_gradient_norm;   

   /// Value for the parameters norm at which the training process is assumed to fail. 
   
   double error_parameters_norm;

   /// Value for the gradient norm at which the training process is assumed to fail. 

   double error_gradient_norm;


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

   /// True if the Hessian history vector of matrices is to be reserved, false otherwise.

   bool reserve_Hessian_approximation_history;

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
