/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */ 
/*   Q U A S I - N E W T O N   M E T H O D    C L A S S                                                         */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// OpenNN includes

#include "quasi_newton_method.h"

//#include"windows.h"

namespace OpenNN
{

// DEFAULT CONSTRUCTOR

/// Default constructor. 
/// It creates a quasi-Newton method training algorithm not associated to any performance functional. 
/// It also initializes the class members to their default values.

QuasiNewtonMethod::QuasiNewtonMethod(void) 
 : TrainingAlgorithm()
{
   set_default();
}


// PERFORMANCE FUNCTIONAL CONSTRUCTOR

/// Performance functional constructor. 
/// It creates a quasi-Newton method training algorithm associated to a performance functional. 
/// It also initializes the class members to their default values.
/// @param new_performance_functional_pointer Pointer to a performance functional object.

QuasiNewtonMethod::QuasiNewtonMethod(PerformanceFunctional* new_performance_functional_pointer)
: TrainingAlgorithm(new_performance_functional_pointer)
{
   training_rate_algorithm.set_performance_functional_pointer(new_performance_functional_pointer);

   set_default();
}


// XML CONSTRUCTOR

/// XML constructor. 
/// It creates a quasi-Newton method training algorithm not associated to any performance functional. 
/// It also initializes the class members to their default values.

QuasiNewtonMethod::QuasiNewtonMethod(const tinyxml2::XMLDocument& document)
 : TrainingAlgorithm(document)
{
   set_default();
}


// DESTRUCTOR

/// Destructor.
/// It does not delete any object. 

QuasiNewtonMethod::~QuasiNewtonMethod(void)
{
}


// METHODS



// const TrainingRateAlgorithm& get_training_rate_algorithm(void) const method

/// Returns a constant reference to the training rate algorithm object inside the quasi-Newton method object. 

const TrainingRateAlgorithm& QuasiNewtonMethod::get_training_rate_algorithm(void) const
{
   return(training_rate_algorithm);
}


// TrainingRateAlgorithm* get_training_rate_algorithm_pointer(void) method

/// Returns a pointer to the training rate algorithm object inside the quasi-Newton method object. 

TrainingRateAlgorithm* QuasiNewtonMethod::get_training_rate_algorithm_pointer(void)
{
   return(&training_rate_algorithm);
}


// const InverseHessianApproximationMethod& get_inverse_Hessian_approximation_method(void) const method

/// Returns the method for approximating the inverse Hessian matrix to be used when training. 

const QuasiNewtonMethod::InverseHessianApproximationMethod& QuasiNewtonMethod::get_inverse_Hessian_approximation_method(void) const
{
   return(inverse_Hessian_approximation_method);
}


// std::string write_inverse_Hessian_approximation_method(void) const method

/// Returns the name of the method for the approximation of the inverse Hessian. 

std::string QuasiNewtonMethod::write_inverse_Hessian_approximation_method(void) const
{
   switch(inverse_Hessian_approximation_method)
   {
      case DFP:
      {
         return("DFP");
	  }
      break;

      case BFGS:
      {
         return("BFGS");
	  }
      break;

	  default:
      {
         std::ostringstream buffer;

         buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
                << "std::string write_inverse_Hessian_approximation_method(void) const method.\n"
                << "Unknown inverse Hessian approximation method.\n";
 
         throw std::logic_error(buffer.str());	     
	  }
      break;
   }
}


// const double& get_warning_parameters_norm(void) const method

/// Returns the minimum value for the norm of the parameters vector at wich a warning message is written to the screen. 

const double& QuasiNewtonMethod::get_warning_parameters_norm(void) const
{
   return(warning_parameters_norm);       
}


// const double& get_warning_gradient_norm(void) const method

/// Returns the minimum value for the norm of the gradient vector at wich a warning message is written to the screen. 

const double& QuasiNewtonMethod::get_warning_gradient_norm(void) const
{
   return(warning_gradient_norm);       
}


// const double& get_warning_training_rate(void) const method

/// Returns the training rate value at wich a warning message is written to the screen during line minimization.

const double& QuasiNewtonMethod::get_warning_training_rate(void) const
{
   return(warning_training_rate);
}


// const double& get_error_parameters_norm(void) const method

/// Returns the value for the norm of the parameters vector at wich an error message is written to the screen and the program exits. 

const double& QuasiNewtonMethod::get_error_parameters_norm(void) const
{
   return(error_parameters_norm);
}


// const double& get_error_gradient_norm(void) const method

/// Returns the value for the norm of the gradient vector at wich an error message is written
/// to the screen and the program exits. 

const double& QuasiNewtonMethod::get_error_gradient_norm(void) const
{
   return(error_gradient_norm);
}


// const double& get_error_training_rate(void) const method

/// Returns the training rate value at wich the line minimization algorithm is assumed to fail when 
/// bracketing a minimum.

const double& QuasiNewtonMethod::get_error_training_rate(void) const
{
   return(error_training_rate);
}


// const double& get_minimum_parameters_increment_norm(void) const method

/// Returns the minimum norm of the parameter increment vector used as a stopping criteria when training. 

const double& QuasiNewtonMethod::get_minimum_parameters_increment_norm(void) const
{
   return(minimum_parameters_increment_norm);
}


// const double& get_minimum_performance_increase(void) const method

/// Returns the minimum performance improvement during training.  

const double& QuasiNewtonMethod::get_minimum_performance_increase(void) const
{
   return(minimum_performance_increase);
}


// const double& get_performance_goal(void) const method

/// Returns the goal value for the performance. 
/// This is used as a stopping criterion when training a multilayer perceptron

const double& QuasiNewtonMethod::get_performance_goal(void) const
{
   return(performance_goal);
}


// const double& get_gradient_norm_goal(void) const method

/// Returns the goal value for the norm of the objective function gradient.
/// This is used as a stopping criterion when training a multilayer perceptron

const double& QuasiNewtonMethod::get_gradient_norm_goal(void) const
{
   return(gradient_norm_goal);
}


// const unsigned& get_maximum_generalization_performance_decreases(void) const method

/// Returns the maximum number of generalization failures during the training process. 

const unsigned& QuasiNewtonMethod::get_maximum_generalization_performance_decreases(void) const
{
   return(maximum_generalization_performance_decreases);
}


// const unsigned& get_maximum_iterations_number(void) const method

/// Returns the maximum number of iterations for training.

const unsigned& QuasiNewtonMethod::get_maximum_iterations_number(void) const
{
   return(maximum_iterations_number);
}


// const double& get_maximum_time(void) const method

/// Returns the maximum training time.  

const double& QuasiNewtonMethod::get_maximum_time(void) const
{
   return(maximum_time);
}



// const bool& get_reserve_parameters_history(void) const method

/// Returns true if the parameters history matrix is to be reserved, and false otherwise.

const bool& QuasiNewtonMethod::get_reserve_parameters_history(void) const
{
   return(reserve_parameters_history);     
}


// const bool& get_reserve_parameters_norm_history(void) const method 

/// Returns true if the parameters norm history vector is to be reserved, and false otherwise.

const bool& QuasiNewtonMethod::get_reserve_parameters_norm_history(void) const
{
   return(reserve_parameters_norm_history);     
}


// const bool& get_reserve_performance_history(void) const method

/// Returns true if the performance history vector is to be reserved, and false otherwise.

const bool& QuasiNewtonMethod::get_reserve_performance_history(void) const
{
   return(reserve_performance_history);     
}


// const bool& get_reserve_gradient_history(void) const method

/// Returns true if the gradient history vector of vectors is to be reserved, and false otherwise.

const bool& QuasiNewtonMethod::get_reserve_gradient_history(void) const
{
   return(reserve_gradient_history);     
}


// const bool& get_reserve_gradient_norm_history(void) const method

/// Returns true if the gradient norm history vector is to be reserved, and false otherwise.

const bool& QuasiNewtonMethod::get_reserve_gradient_norm_history(void) const
{
   return(reserve_gradient_norm_history);     
}



// const bool& get_reserve_training_direction_history(void) const method

/// Returns true if the training direction history matrix is to be reserved, and false otherwise.

const bool& QuasiNewtonMethod::get_reserve_training_direction_history(void) const
{
   return(reserve_training_direction_history);     
}


// const bool& get_reserve_training_rate_history(void) const method

/// Returns true if the training rate history vector is to be reserved, and false otherwise.

const bool& QuasiNewtonMethod::get_reserve_training_rate_history(void) const
{
   return(reserve_training_rate_history);     
}


// const bool& get_reserve_elapsed_time_history(void) const method

/// Returns true if the elapsed time history vector is to be reserved, and false otherwise.

const bool& QuasiNewtonMethod::get_reserve_elapsed_time_history(void) const
{
   return(reserve_elapsed_time_history);     
}


// const bool& get_reserve_inverse_Hessian_history(void) const method

/// Returns true if the inverse Hessian history is to be reserved, and false otherwise.

const bool& QuasiNewtonMethod::get_reserve_inverse_Hessian_history(void) const
{
   return(reserve_inverse_Hessian_history);     
}


// const bool& get_reserve_generalization_performance_history(void) const method

/// Returns true if the Generalization performance history vector is to be reserved, and false otherwise.

const bool& QuasiNewtonMethod::get_reserve_generalization_performance_history(void) const
{
   return(reserve_generalization_performance_history);
}


// const unsigned& get_display_period(void) const method

/// Returns the number of iterations between the training showing progress. 

const unsigned& QuasiNewtonMethod::get_display_period(void) const
{
   return(display_period);
}


// void set_performance_functional_pointer(PerformanceFunctional*) method

/// Sets a pointer to a performance functional object to be associated to the quasi-Newton method object.
/// It also sets that performance functional to the training rate algorithm.
/// @param new_performance_functional_pointer Pointer to a performance functional object.

void QuasiNewtonMethod::set_performance_functional_pointer(PerformanceFunctional* new_performance_functional_pointer)
{
   performance_functional_pointer = new_performance_functional_pointer;

   training_rate_algorithm.set_performance_functional_pointer(new_performance_functional_pointer);
}


// void set_inverse_Hessian_approximation_method(const InverseHessianApproximationMethod&) method

/// Sets a new inverse Hessian approximatation method value. 
/// @param new_inverse_Hessian_approximation_method Inverse Hessian approximation method value.

void QuasiNewtonMethod::set_inverse_Hessian_approximation_method(const QuasiNewtonMethod::InverseHessianApproximationMethod& 
new_inverse_Hessian_approximation_method)
{
   inverse_Hessian_approximation_method = new_inverse_Hessian_approximation_method;
}


// void set_inverse_Hessian_approximation_method(const std::string&) method

/// Sets a new method for approximating the inverse of the Hessian matrix from a string containing the name. 
/// Possible values are:
/// <ul>
/// <li> "DFP"
/// <li> "BFGS"
/// </ul>
/// @param new_inverse_Hessian_approximation_method_name Name of inverse Hessian approximation method.  

void QuasiNewtonMethod::set_inverse_Hessian_approximation_method(const std::string& new_inverse_Hessian_approximation_method_name)
{
   if(new_inverse_Hessian_approximation_method_name == "DFP")
   {
      inverse_Hessian_approximation_method = DFP;
   }
   else if(new_inverse_Hessian_approximation_method_name == "BFGS")
   {
      inverse_Hessian_approximation_method = BFGS;
   }
   else
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "void set_inverse_Hessian_approximation_method(const std::string&) method.\n"
			 << "Unknown inverse Hessian approximation method: " << new_inverse_Hessian_approximation_method_name << ".\n";
   
      throw std::logic_error(buffer.str());	  
   }
}


// void set_reserve_all_training_history(bool) method

/// Makes the training history of all variables to reseved or not in memory.
/// @param new_reserve_all_training_history True if the training history of all variables is to be reserved, 
/// false otherwise.

void QuasiNewtonMethod::set_reserve_all_training_history(const bool& new_reserve_all_training_history)
{
   reserve_elapsed_time_history = new_reserve_all_training_history;
   reserve_parameters_history = new_reserve_all_training_history;
   reserve_parameters_norm_history = new_reserve_all_training_history;
   reserve_performance_history = new_reserve_all_training_history;
   reserve_gradient_history = new_reserve_all_training_history;
   reserve_gradient_norm_history = new_reserve_all_training_history;
   reserve_training_direction_history = new_reserve_all_training_history;
   reserve_training_rate_history = new_reserve_all_training_history;
}


// void set_default(void) method

void QuasiNewtonMethod::set_default(void)
{
   inverse_Hessian_approximation_method = BFGS;

   training_rate_algorithm.set_default();

   // TRAINING PARAMETERS

   warning_parameters_norm = 1.0e3;
   warning_gradient_norm = 1.0e3;
   warning_training_rate = 1.0e3;

   error_parameters_norm = 1.0e6;
   error_gradient_norm = 1.0e6;
   error_training_rate = 1.0e6;

   // STOPPING CRITERIA

   minimum_parameters_increment_norm = 0.0;

   minimum_performance_increase = 0.0;
   performance_goal = -1.0e99;
   gradient_norm_goal = 0.0;
   maximum_generalization_performance_decreases = 1000000;

   maximum_iterations_number = 1000;
   maximum_time = 1000.0;

   // TRAINING HISTORY

   reserve_parameters_history = false;
   reserve_parameters_norm_history = false;

   reserve_performance_history = true;
   reserve_gradient_history = false;
   reserve_gradient_norm_history = false;
   reserve_generalization_performance_history = false;
   reserve_inverse_Hessian_history = false;

   reserve_training_direction_history = false;
   reserve_training_rate_history = false;
   reserve_elapsed_time_history = false;

   // UTILITIES

   display = true;
   display_period = 10;
}


// void set_warning_parameters_norm(const double&) method

/// Sets a new value for the parameters vector norm at which a warning message is written to the 
/// screen. 
/// @param new_warning_parameters_norm Warning norm of parameters vector value. 

void QuasiNewtonMethod::set_warning_parameters_norm(const double& new_warning_parameters_norm)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_warning_parameters_norm < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "void set_warning_parameters_norm(const double&) method.\n"
             << "Warning parameters norm must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set warning parameters norm

   warning_parameters_norm = new_warning_parameters_norm;     
}


// void set_warning_gradient_norm(const double&) method

/// Sets a new value for the gradient vector norm at which 
/// a warning message is written to the screen. 
/// @param new_warning_gradient_norm Warning norm of gradient vector value. 

void QuasiNewtonMethod::set_warning_gradient_norm(const double& new_warning_gradient_norm)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_warning_gradient_norm < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "void set_warning_gradient_norm(const double&) method.\n"
             << "Warning gradient norm must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set warning gradient norm

   warning_gradient_norm = new_warning_gradient_norm;     
}


// void set_warning_training_rate(const double&) method

/// Sets a new training rate value at wich a warning message is written to the screen during line 
/// minimization.
/// @param new_warning_training_rate Warning training rate value.

void QuasiNewtonMethod::set_warning_training_rate(const double& new_warning_training_rate)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_warning_training_rate < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n" 
             << "void set_warning_training_rate(const double&) method.\n"
             << "Warning training rate must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   warning_training_rate = new_warning_training_rate;
}


// void set_error_parameters_norm(const double&) method

/// Sets a new value for the parameters vector norm at which an error message is written to the 
/// screen and the program exits. 
/// @param new_error_parameters_norm Error norm of parameters vector value. 

void QuasiNewtonMethod::set_error_parameters_norm(const double& new_error_parameters_norm)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_error_parameters_norm < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "void set_error_parameters_norm(const double&) method.\n"
             << "Error parameters norm must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set error parameters norm

   error_parameters_norm = new_error_parameters_norm;
}


// void set_error_gradient_norm(const double&) method

/// Sets a new value for the gradient vector norm at which an error message is written to the screen 
/// and the program exits. 
/// @param new_error_gradient_norm Error norm of gradient vector value. 

void QuasiNewtonMethod::set_error_gradient_norm(const double& new_error_gradient_norm)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_error_gradient_norm < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "void set_error_gradient_norm(const double&) method.\n"
             << "Error gradient norm must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set error gradient norm

   error_gradient_norm = new_error_gradient_norm;
}


// void set_error_training_rate(const double&) method

/// Sets a new training rate value at wich a the line minimization algorithm is assumed to fail when 
/// bracketing a minimum.
/// @param new_error_training_rate Error training rate value.

void QuasiNewtonMethod::set_error_training_rate(const double& new_error_training_rate)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_error_training_rate < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "void set_error_training_rate(const double&) method.\n"
             << "Error training rate must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set error training rate

   error_training_rate = new_error_training_rate;
}


// void set_minimum_parameters_increment_norm(const double&) method

/// Sets a new value for the minimum parameters increment norm stopping criterion. 
/// @param new_minimum_parameters_increment_norm Value of norm of parameters increment norm used to stop training. 

void QuasiNewtonMethod::set_minimum_parameters_increment_norm(const double& new_minimum_parameters_increment_norm)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_minimum_parameters_increment_norm < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "void new_minimum_parameters_increment_norm(const double&) method.\n"
             << "Minimum parameters increment norm must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set error training rate

   minimum_parameters_increment_norm = new_minimum_parameters_increment_norm;
}


// void set_minimum_performance_increase(const double&) method

/// Sets a new minimum performance improvement during training.  
/// @param new_minimum_performance_increase Minimum improvement in the performance between two iterations.

void QuasiNewtonMethod::set_minimum_performance_increase(const double& new_minimum_performance_increase)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_minimum_performance_increase < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "void set_minimum_performance_increase(const double&) method.\n"
             << "Minimum performance improvement must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set minimum performance improvement

   minimum_performance_increase = new_minimum_performance_increase;
}


// void set_performance_goal(const double&) method

/// Sets a new goal value for the performance. 
/// This is used as a stopping criterion when training a multilayer perceptron
/// @param new_performance_goal Goal value for the performance.

void QuasiNewtonMethod::set_performance_goal(const double& new_performance_goal)
{
   performance_goal = new_performance_goal;
}


// void set_gradient_norm_goal(const double&) method

/// Sets a new the goal value for the norm of the objective function gradient. 
/// This is used as a stopping criterion when training a multilayer perceptron
/// @param new_gradient_norm_goal Goal value for the norm of the objective function gradient.

void QuasiNewtonMethod::set_gradient_norm_goal(const double& new_gradient_norm_goal)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_gradient_norm_goal < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "void set_gradient_norm_goal(const double&) method.\n"
             << "Gradient norm goal must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set gradient norm goal

   gradient_norm_goal = new_gradient_norm_goal;
}


// void set_maximum_generalization_performance_decreases(const unsigned&) method

/// Sets a new maximum number of generalization failures. 
/// @param new_maximum_generalization_performance_decreases Maximum number of iterations in which the generalization evalutation decreases.

void QuasiNewtonMethod::set_maximum_generalization_performance_decreases(const unsigned& new_maximum_generalization_performance_decreases)
{
   // Set maximum generalization performace decrases

   maximum_generalization_performance_decreases = new_maximum_generalization_performance_decreases;
}


// void set_maximum_iterations_number(unsigned) method

/// Sets a maximum number of iterations for training.
/// @param new_maximum_iterations_number Maximum number of iterations for training.

void QuasiNewtonMethod::set_maximum_iterations_number(const unsigned& new_maximum_iterations_number)
{
   // Set maximum iterations number

   maximum_iterations_number = new_maximum_iterations_number;
}


// void set_maximum_time(const double&) method

/// Sets a new maximum training time.  
/// @param new_maximum_time Maximum training time.

void QuasiNewtonMethod::set_maximum_time(const double& new_maximum_time)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_maximum_time < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "void set_maximum_time(const double&) method.\n"
             << "Maximum time must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }
   
   #endif

   // Set maximum time

   maximum_time = new_maximum_time;
}


// void set_reserve_parameters_history(bool) method

/// Makes the parameters history vector of vectors to be reseved or not in memory.
/// @param new_reserve_parameters_history True if the parameters history vector of vectors is to be reserved, false otherwise.

void QuasiNewtonMethod::set_reserve_parameters_history(const bool& new_reserve_parameters_history)
{
   reserve_parameters_history = new_reserve_parameters_history;     
}


// void set_reserve_parameters_norm_history(bool) method

/// Makes the parameters norm history vector to be reseved or not in memory.
/// @param new_reserve_parameters_norm_history True if the parameters norm history vector is to be reserved, false otherwise.

void QuasiNewtonMethod::set_reserve_parameters_norm_history(const bool& new_reserve_parameters_norm_history)
{
   reserve_parameters_norm_history = new_reserve_parameters_norm_history;     
}


// void set_reserve_performance_history(bool) method

/// Makes the performance history vector to be reseved or not in memory.
/// @param new_reserve_performance_history True if the performance history vector is to be reserved, false otherwise.

void QuasiNewtonMethod::set_reserve_performance_history(const bool& new_reserve_performance_history)
{
   reserve_performance_history = new_reserve_performance_history;     
}


// void set_reserve_gradient_history(bool) method

/// Makes the gradient history vector of vectors to be reseved or not in memory.
/// @param new_reserve_gradient_history True if the gradient history matrix is to be reserved, false otherwise.

void QuasiNewtonMethod::set_reserve_gradient_history(const bool& new_reserve_gradient_history)
{
   reserve_gradient_history = new_reserve_gradient_history;    
}


// void set_reserve_gradient_norm_history(bool) method

/// Makes the gradient norm history vector to be reseved or not in memory.
/// @param new_reserve_gradient_norm_history True if the gradient norm history matrix is to be reserved, false 
/// otherwise.

void QuasiNewtonMethod::set_reserve_gradient_norm_history(const bool& new_reserve_gradient_norm_history)
{
   reserve_gradient_norm_history = new_reserve_gradient_norm_history;     
}


// void set_reserve_inverse_Hessian_history(bool) method

/// Sets the history of the inverse of the Hessian matrix to be reserved or not in memory.
/// This is a vector of matrices. 
/// @param new_reserve_inverse_Hessian_history True if the inverse Hessian history is to be reserved, false otherwise. 

void QuasiNewtonMethod::set_reserve_inverse_Hessian_history(const bool& new_reserve_inverse_Hessian_history)
{
   reserve_inverse_Hessian_history = new_reserve_inverse_Hessian_history;
}


// void set_reserve_training_direction_history(bool) method

/// Makes the training direction history vector of vectors to be reseved or not in memory.
/// @param new_reserve_training_direction_history True if the training direction history matrix is to be reserved, 
/// false otherwise.

void QuasiNewtonMethod::set_reserve_training_direction_history(const bool& new_reserve_training_direction_history)
{
   reserve_training_direction_history = new_reserve_training_direction_history;          
}


// void set_reserve_training_rate_history(bool) method

/// Makes the training rate history vector to be reseved or not in memory.
/// @param new_reserve_training_rate_history True if the training rate history vector is to be reserved, false 
/// otherwise.

void QuasiNewtonMethod::set_reserve_training_rate_history(const bool& new_reserve_training_rate_history)
{
   reserve_training_rate_history = new_reserve_training_rate_history;          
}


// void set_reserve_elapsed_time_history(bool) method

/// Makes the elapsed time over the iterations to be reseved or not in memory. This is a vector.
/// @param new_reserve_elapsed_time_history True if the elapsed time history vector is to be reserved, false 
/// otherwise.

void QuasiNewtonMethod::set_reserve_elapsed_time_history(const bool& new_reserve_elapsed_time_history)
{
   reserve_elapsed_time_history = new_reserve_elapsed_time_history;     
}


// void set_reserve_generalization_performance_history(bool) method

/// Makes the Generalization performance history to be reserved or not in memory. 
/// This is a vector. 
/// @param new_reserve_generalization_performance_history True if the Generalization performance history is to be reserved, false otherwise. 

void QuasiNewtonMethod::set_reserve_generalization_performance_history(const bool& new_reserve_generalization_performance_history)  
{
   reserve_generalization_performance_history = new_reserve_generalization_performance_history;
}


// void set_display_period(const unsigned&) method

/// Sets a new number of iterations between the training showing progress. 
/// @param new_display_period
/// Number of iterations between the training showing progress. 

void QuasiNewtonMethod::set_display_period(const unsigned& new_display_period)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 
     
   if(new_display_period == 0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "void set_display_period(const unsigned&) method.\n"
             << "Display period must be greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   display_period = new_display_period;
}


// Vector<double> calculate_inverse_Hessian_approximation(
// const Vector<double>&, const Vector<double>&, 
// const Vector<double>&, const Vector<double>&, 
// const Matrix<double>&) method

/// Calculates an approximation of the inverse Hessian, accoring to the method used. 
/// @param old_parameters Another point of the objective function.
/// @param parameters Current point of the objective function
/// @param old_gradient Gradient at the other point. 
/// @param gradient Gradient at the current point. 
/// @param old_inverse_Hessian Inverse Hessian at the other point of the objective function.

Matrix<double> QuasiNewtonMethod::calculate_inverse_Hessian_approximation(
const Vector<double>& old_parameters, const Vector<double>& parameters, 
const Vector<double>& old_gradient, const Vector<double>& gradient,
const Matrix<double>& old_inverse_Hessian) const
{
   switch(inverse_Hessian_approximation_method)
   {
      case DFP:
      {
         return(calculate_DFP_inverse_Hessian(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian));
      }
      break;

      case BFGS:
      {
         return(calculate_BFGS_inverse_Hessian(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian));
      }
      break;

	  default:
	  {
         std::ostringstream buffer;

         buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
                << "Vector<double> calculate_inverse_Hessian_approximation(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
                << "Unknown inverse Hessian approximation method.\n";

         throw std::logic_error(buffer.str());	     
	  }
	  break;
   }
}


// Vector<double> calculate_training_direction(const Vector<double>&, const Matrix<double>&) const method

/// Returns the quasi-Newton method training direction, which has been previously normalized.
/// @param gradient Gradient vector. 
/// @param inverse_Hessian_approximation Inverse Hessian approximation matrix. 

Vector<double> QuasiNewtonMethod::calculate_training_direction(const Vector<double>& gradient, const Matrix<double>& inverse_Hessian_approximation) const
{
   const Vector<double> training_direction = inverse_Hessian_approximation.dot(gradient)*(-1.0);
 
   const double training_direction_norm = training_direction.calculate_norm();

   return(training_direction/training_direction_norm);
}


// Vector<double> calculate_gradient_descent_training_direction(const Vector<double>&) const method

/// Returns the gradient descent training direction, which is the negative of the normalized gradient. 
/// @param gradient Gradient vector.

Vector<double> QuasiNewtonMethod::calculate_gradient_descent_training_direction(const Vector<double>& gradient) const
{
    // Control sentence (if debug)

    #ifndef NDEBUG

    std::ostringstream buffer;

    if(!performance_functional_pointer)
    {
       buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
              << "Vector<double> calculate_gradient_descent_training_direction(const Vector<double>&) const method.\n"
              << "Performance functional pointer is NULL.\n";

       throw std::logic_error(buffer.str());
    }

    #endif

    const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

    const unsigned parameters_number = neural_network_pointer->count_parameters_number();

    #ifndef NDEBUG

    const unsigned gradient_size = gradient.size();

    if(gradient_size != parameters_number)
    {
       buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
              << "Vector<double> calculate_gradient_descent_training_direction(const Vector<double>&) const method.\n"
              << "Size of gradient (" << gradient_size << ") is not equal to number of parameters (" << parameters_number << ").\n";

       throw std::logic_error(buffer.str());
    }

    #endif

    return(gradient.calculate_normalized()*(-1.0));
}


// Matrix<double> calculate_DFP_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method

/// Returns an approximation of the inverse Hessian matrix according to the Davidon-Fletcher-Powel 
/// (DFP) algorithm. 
/// @param old_parameters A previous set of parameters.
/// @param old_gradient The gradient of the objective function for that previous set of parameters.
/// @param old_inverse_Hessian The Hessian of the objective function for that previous set of parameters.
/// @param parameters Actual set of parameters.
/// @param gradient The gradient of the objective function for the actual set of parameters.

Matrix<double> QuasiNewtonMethod::calculate_DFP_inverse_Hessian(
const Vector<double>& old_parameters, const Vector<double>& parameters, const Vector<double>& old_gradient, const Vector<double>& gradient, const Matrix<double>& old_inverse_Hessian) const
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   std::ostringstream buffer;

   const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   const unsigned old_parameters_size = old_parameters.size();
   const unsigned parameters_size = parameters.size();

   if(old_parameters_size != parameters_number)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_DFP_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Size of old parameters vector must be equal to number of parameters.\n";

      throw std::logic_error(buffer.str());
   }
   else if(parameters_size != parameters_number)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_DFP_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Size of parameters vector must be equal to number of parameters.\n";

      throw std::logic_error(buffer.str());
   }

   const unsigned old_gradient_size = old_gradient.size();
   const unsigned gradient_size = gradient.size();
    
   if(old_gradient_size != parameters_number)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_DFP_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Size of old gradient vector must be equal to number of parameters.\n";

      throw std::logic_error(buffer.str());
   }
   else if(gradient_size != parameters_number)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_DFP_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Size of gradient vector must be equal to number of parameters.\n";

      throw std::logic_error(buffer.str());
   }

   const unsigned rows_number = old_inverse_Hessian.get_rows_number();
   const unsigned columns_number = old_inverse_Hessian.get_columns_number();

   if(rows_number != parameters_number)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_DFP_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Number of rows in old inverse Hessian must be equal to number of parameters.\n";

      throw std::logic_error(buffer.str());
   }
   else if(columns_number != parameters_number)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_DFP_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Number of columns in old inverse Hessian must be equal to number of parameters.\n";

      throw std::logic_error(buffer.str());
   }
 
   #endif

   // Parameters difference Vector
   
   const Vector<double> parameters_difference = parameters - old_parameters;
   
   // Control sentence (if debug)

   if(parameters_difference.calculate_absolute_value() < 1.0e-50)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_DFP_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Parameters difference vector is zero.\n";

      throw std::logic_error(buffer.str());	  
   }

   // Gradient difference Vector
   
   const Vector<double> gradient_difference = gradient - old_gradient;

   if(gradient_difference.calculate_absolute_value() < 1.0e-50)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_DFP_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Gradient difference vector is zero.\n";

      throw std::logic_error(buffer.str());	  
   }

   if(old_inverse_Hessian.calculate_absolute_value() < 1.0e-50)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_DFP_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Old inverse Hessian matrix is zero.\n";

      throw std::logic_error(buffer.str());	  
   }

   if(fabs(parameters_difference.dot(gradient_difference)) < 1.0e-50)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_DFP_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Denominator of first term is zero.\n";

      throw std::logic_error(buffer.str());	  
   }
   else if(fabs(gradient_difference.dot(old_inverse_Hessian).dot(gradient_difference)) < 1.0e-50)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_DFP_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Denominator of second term is zero.\n";

      throw std::logic_error(buffer.str());	  
   }

   const Matrix<double> DFP_inverse_Hessian = old_inverse_Hessian
   + parameters_difference.direct(parameters_difference)
   /parameters_difference.dot(gradient_difference)
   - (old_inverse_Hessian.dot(gradient_difference)).direct(old_inverse_Hessian.dot(gradient_difference))
   /gradient_difference.dot(old_inverse_Hessian).dot(gradient_difference);

   return(DFP_inverse_Hessian);               

}


// Matrix<double> calculate_BFGS_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Matrix<double>&, const Vector<double>&, const Vector<double>&) method

/// Returns an approximation of the inverse Hessian matrix according to the 
/// Broyden-Fletcher-Goldfarb-Shanno (BGFS) algorithm. 
/// @param old_parameters A previous set of parameters.
/// @param old_gradient The gradient of the objective function for that previous set of parameters.
/// @param old_inverse_Hessian The Hessian of the objective function for that previous set of parameters.
/// @param parameters Actual set of parameters.
/// @param gradient The gradient of the objective function for the actual set of parameters.

Matrix<double> QuasiNewtonMethod::calculate_BFGS_inverse_Hessian(
const Vector<double>& old_parameters, const Vector<double>& parameters, const Vector<double>& old_gradient, const Vector<double>& gradient, const Matrix<double>& old_inverse_Hessian) const
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

    std::ostringstream buffer;

    const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   const unsigned old_parameters_size = old_parameters.size();
   const unsigned parameters_size = parameters.size();
    
   if(old_parameters_size != parameters_number)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_BFGS_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Size of old parameters vector must be equal to number of parameters.\n";

      throw std::logic_error(buffer.str());	  
   }
   else if(parameters_size != parameters_number)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_BFGS_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Size of parameters vector must be equal to number of parameters.\n";

      throw std::logic_error(buffer.str());	  
   }

   const unsigned old_gradient_size = old_gradient.size();

   if(old_gradient_size != parameters_number)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_BFGS_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method." 
             << std::endl
             << "Size of old gradient vector must be equal to number of parameters.\n";

      throw std::logic_error(buffer.str());	  
   }

   const unsigned gradient_size = gradient.size();

   if(gradient_size != parameters_number)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_BFGS_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method." 
             << std::endl
             << "Size of gradient vector must be equal to number of parameters.\n";

      throw std::logic_error(buffer.str());	  
   }

   const unsigned rows_number = old_inverse_Hessian.get_rows_number();
   const unsigned columns_number = old_inverse_Hessian.get_columns_number();

   if(rows_number != parameters_number)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_BFGS_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Number of rows in old inverse Hessian must be equal to number of parameters.\n";

      throw std::logic_error(buffer.str());	  
   }

   if(columns_number != parameters_number)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_BFGS_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Number of columns in old inverse Hessian must be equal to number of parameters.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Parameters difference Vector
   
   const Vector<double> parameters_difference = parameters - old_parameters;


   if(parameters_difference.calculate_absolute_value() < 1.0e-50)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_BFGS_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Parameters difference vector is zero.\n";

      throw std::logic_error(buffer.str());	  
   }

   // Gradient difference Vector
   
   const Vector<double> gradient_difference = gradient - old_gradient;

   if(gradient_difference.calculate_absolute_value() < 1.0e-50)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_BFGS_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Gradient difference vector is zero.\n";

      throw std::logic_error(buffer.str());	  
   }

   if(old_inverse_Hessian.calculate_absolute_value() < 1.0e-50)
   {
      buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
             << "Matrix<double> calculate_BFGS_inverse_Hessian(const Vector<double>&, const Vector<double>&, const Vector<double>&, const Vector<double>&, const Matrix<double>&) method.\n"
             << "Old inverse Hessian matrix is zero.\n";
   
	  throw std::logic_error(buffer.str());
   }


   // BGFS Vector

   const Vector<double> BFGS = parameters_difference/parameters_difference.dot(gradient_difference)
   - old_inverse_Hessian.dot(gradient_difference)
   /gradient_difference.dot(old_inverse_Hessian).dot(gradient_difference);

   // Calculate inverse Hessian approximation

   const Matrix<double> BFGS_inverse_Hessian = old_inverse_Hessian
   + parameters_difference.direct(parameters_difference)
   /parameters_difference.dot(gradient_difference) 
   - (old_inverse_Hessian.dot(gradient_difference)).direct(gradient_difference.dot(old_inverse_Hessian))
   /gradient_difference.dot(old_inverse_Hessian).dot(gradient_difference)
   + (BFGS.direct(BFGS))*(gradient_difference.dot(old_inverse_Hessian).dot(gradient_difference));   
   
   return(BFGS_inverse_Hessian);               
}


// void resize_training_history(const unsigned&) method

/// Resizes all the training history variables. 
/// @param new_size Size of training history variables. 

void QuasiNewtonMethod::QuasiNewtonMethodResults::resize_training_history(const unsigned& new_size)
{
    // Control sentence (if debug)

    #ifndef NDEBUG

    if(quasi_Newton_method_pointer == NULL)
    {
       std::ostringstream buffer;

       buffer << "OpenNN Exception: QuasiNewtonMethodResults structure.\n"
              << "void resize_training_history(const unsigned&) method.\n"
              << "Gradient descent pointer is NULL.\n";

       throw std::logic_error(buffer.str());
    }

    #endif

    if(quasi_Newton_method_pointer->get_reserve_parameters_history())
   {
      parameters_history.resize(new_size);
   }

   if(quasi_Newton_method_pointer->get_reserve_parameters_norm_history())
   {
      parameters_norm_history.resize(new_size);
   }


   if(quasi_Newton_method_pointer->get_reserve_performance_history())
   {
      performance_history.resize(new_size);
   }

   if(quasi_Newton_method_pointer->get_reserve_generalization_performance_history())
   {
      generalization_performance_history.resize(new_size);
   }

   if(quasi_Newton_method_pointer->get_reserve_gradient_history())
   {
      gradient_history.resize(new_size);
   }

   if(quasi_Newton_method_pointer->get_reserve_gradient_norm_history())
   {
      gradient_norm_history.resize(new_size);
   }

   if(quasi_Newton_method_pointer->get_reserve_inverse_Hessian_history())
   {
      inverse_Hessian_history.resize(new_size);
   }
   
   if(quasi_Newton_method_pointer->get_reserve_training_direction_history())
   {
      training_direction_history.resize(new_size);
   }

   if(quasi_Newton_method_pointer->get_reserve_training_rate_history())
   {
      training_rate_history.resize(new_size);
   }

   if(quasi_Newton_method_pointer->get_reserve_elapsed_time_history())
   {
      elapsed_time_history.resize(new_size);
   }
}


// std::string to_string(void) const method

/// Returns a string representation of the current quasi-Newton method results structure. 

std::string QuasiNewtonMethod::QuasiNewtonMethodResults::to_string(void) const
{
   std::ostringstream buffer;

   buffer << "% Quasi-Newton method results\n";

   // Parameters history

   if(!parameters_history.empty())
   {
	  if(!parameters_history[0].empty())
	  {
          buffer << "% Parameters history:\n"
                 << parameters_history << "\n"; 
	  }
   }

   // Parameters norm history

   if(!parameters_norm_history.empty())
   {
       buffer << "% Parameters norm history:\n"
              << parameters_norm_history << "\n"; 
   }
   
   // Performance history   

   if(!performance_history.empty())
   {
       buffer << "% Performance history:\n"
              << performance_history << "\n"; 
   }

   // Generalization performance history

   if(!generalization_performance_history.empty())
   {
       buffer << "% Generalization performance history:\n"
              << generalization_performance_history << "\n"; 
   }

   // Gradient history 

   if(!gradient_history.empty())
   {
	   if(!gradient_history[0].empty())
	   {
          buffer << "% Gradient history:\n"
                 << gradient_history << "\n"; 
	   }
   }

   // Gradient norm history

   if(!gradient_norm_history.empty())
   {
       buffer << "% Gradient norm history:\n"
              << gradient_norm_history << "\n"; 
   }

   // Inverse Hessian history

   if(!inverse_Hessian_history.empty())
   {
	   if(!inverse_Hessian_history[0].empty())
	   {
          buffer << "% Inverse Hessian history:\n"
                 << inverse_Hessian_history << "\n"; 
	   }
   }

   // Training direction history

   if(!training_direction_history.empty())
   {
	   if(!training_direction_history[0].empty())
	   {
          buffer << "% Training direction history:\n"
                 << training_direction_history << "\n"; 
	   }
   }

   // Training rate history

   if(!training_rate_history.empty())
   {
       buffer << "% Training rate history:\n"
              << training_rate_history << "\n"; 
   }

   // Elapsed time history

   if(!elapsed_time_history.empty())
   {
       buffer << "% Elapsed time history:\n"
              << elapsed_time_history << "\n"; 
   }

   return(buffer.str());
}


// Matrix<std::string> write_final_results(const unsigned& precision) const method

Matrix<std::string> QuasiNewtonMethod::QuasiNewtonMethodResults::write_final_results(const unsigned& precision) const
{
   std::ostringstream buffer;

   Vector<std::string> names;
   Vector<std::string> values;

   // Final parameters norm

   names.push_back("Final parameters norm");

   buffer.str("");
   buffer << std::setprecision(precision) << final_parameters_norm;

   values.push_back(buffer.str());

   // Final performance

   names.push_back("Final performance");

   buffer.str("");
   buffer << std::setprecision(precision) << final_performance;

   values.push_back(buffer.str());

   // Final generalization performance

   const PerformanceFunctional* performance_functional_pointer = quasi_Newton_method_pointer->get_performance_functional_pointer();

   if(performance_functional_pointer->has_generalization())
   {
       names.push_back("Final generalization performance");

       buffer.str("");
       buffer << std::setprecision(precision) << final_generalization_performance;

       values.push_back(buffer.str());
    }

   // Final gradient norm

   names.push_back("Final gradient norm");

   buffer.str("");
   buffer << std::setprecision(precision) << final_gradient_norm;

   values.push_back(buffer.str());

   // Final training rate

//   names.push_back("Final training rate");

//   buffer.str("");
//   buffer << std::setprecision(precision) << final_training_rate;

//   values.push_back(buffer.str());

   // Iterations number

   names.push_back("Iterations number");

   buffer.str("");
   buffer << iterations_number;

   values.push_back(buffer.str());

   // Elapsed time

   names.push_back("Elapsed time");

   buffer.str("");
   buffer << elapsed_time;

   values.push_back(buffer.str());

   const unsigned rows_number = names.size();
   const unsigned columns_number = 2;

   Matrix<std::string> final_results(rows_number, columns_number);

   final_results.set_column(0, names);
   final_results.set_column(1, values);

   return(final_results);
}


// QuasiNewtonMethodResults* perform_training(void) method

/// Trains a neural network with an associated performance functional according to the quasi-Newton method.
/// Training occurs according to the training operators, training parameters and stopping criteria.

QuasiNewtonMethod::QuasiNewtonMethodResults* QuasiNewtonMethod::perform_training(void)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   check();

   #endif

   // Start training 

   if(display)
   {
      std::cout << "Training with quasi-Newton method...\n";
   }

   QuasiNewtonMethodResults* results_pointer = new QuasiNewtonMethodResults(this);

   results_pointer->resize_training_history(1+maximum_iterations_number);

   // Neural network stuff

   NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   Vector<double> parameters(parameters_number);
   Vector<double> old_parameters(parameters_number);
   double parameters_norm;

   Vector<double> parameters_increment(parameters_number);
   double parameters_increment_norm;

   // Performance functional stuff
     
   double performance = 0.0;
   double old_performance = 0.0;
   double performance_increase = 0.0;

   Vector<double> gradient(parameters_number);
   Vector<double> old_gradient(parameters_number);
   double gradient_norm;

   Matrix<double> inverse_Hessian(parameters_number, parameters_number);
   Matrix<double> old_inverse_Hessian(parameters_number, parameters_number);

   double generalization_performance = 0.0; 
   double old_generalization_performance = 0.0;

   // Training algorithm stuff 

   Vector<double> training_direction(parameters_number);

   double training_slope;

   //   const double& first_training_rate = training_rate_algorithm.get_first_training_rate();
   const double first_training_rate = 0.01;

   double initial_training_rate = 0.0;
   double training_rate = 0.0;
   double old_training_rate = 0.0;

   Vector<double> directional_point(2);
   directional_point[0] = 0.0;
   directional_point[1] = 0.0;

   bool stop_training = false;

   unsigned generalization_failures = 0;

   time_t beginning_time, current_time;
   time(&beginning_time);
   double elapsed_time;

   unsigned iteration;

   // Main loop 

   for(iteration = 0; iteration <= maximum_iterations_number; iteration++)
   {
      // Neural network

      parameters = neural_network_pointer->arrange_parameters();

      parameters_norm = parameters.calculate_norm();

      if(display && parameters_norm >= warning_parameters_norm)
      {
         std::cout << "OpenNN Warning: Parameters norm is " << parameters_norm << ".\n";          
      }

      // Performance functional stuff

      if(iteration == 0)
      {      
         performance = performance_functional_pointer->calculate_performance();
         performance_increase = 0.0; 
      }
      else
      {
         performance = directional_point[1];
         performance_increase = old_performance - performance; 
      }

      gradient = performance_functional_pointer->calculate_gradient();

      gradient_norm = gradient.calculate_norm();

      if(display && gradient_norm >= warning_gradient_norm)
      {
         std::cout << "OpenNN Warning: Gradient norm is " << gradient_norm << ".\n";          
      }

      if(iteration == 0)
      {
         inverse_Hessian.initialize_identity();
      }
      else
      {
          inverse_Hessian = calculate_inverse_Hessian_approximation(old_parameters, parameters, old_gradient, gradient, old_inverse_Hessian);
      }

      generalization_performance = performance_functional_pointer->calculate_generalization_performance();

      if(iteration != 0 && generalization_performance > old_generalization_performance)
      {
         generalization_failures++;	  
      }

      // Training algorithm 

      training_direction = calculate_training_direction(gradient, inverse_Hessian);          

      // Calculate performance training slope

      training_slope = (gradient/gradient_norm).dot(training_direction);

      // Check for a descent direction 

      if(training_slope >= 0.0)
      {
         // Reset training direction

         training_direction = calculate_gradient_descent_training_direction(gradient);
      }

      // Get initial training rate

      if(iteration == 0)
      {
         initial_training_rate = first_training_rate;
      }
      else
      {
         initial_training_rate = old_training_rate;
      }

      directional_point = training_rate_algorithm.calculate_directional_point(performance, training_direction, initial_training_rate);

      training_rate = directional_point[0];      

      if(iteration != 0 && training_rate < 1.0e-99)
      {
         // Reset training direction

         training_direction = calculate_gradient_descent_training_direction(gradient);         

         directional_point = training_rate_algorithm.calculate_directional_point(performance, training_direction, first_training_rate);

         training_rate = directional_point[0];
      }

      parameters_increment = training_direction*training_rate;
      parameters_increment_norm = parameters_increment.calculate_norm();
      
      // Elapsed time

      time(&current_time);
      elapsed_time = difftime(current_time, beginning_time);

      // Training history multilayer perceptron 

      if(reserve_parameters_history)
      {
         results_pointer->parameters_history[iteration] = parameters;                                
      }

      if(reserve_parameters_norm_history)
      {
         results_pointer->parameters_norm_history[iteration] = parameters_norm; 
      }

      if(reserve_performance_history)
      {
         results_pointer->performance_history[iteration] = performance;
      }

      if(reserve_generalization_performance_history)
      {
         results_pointer->generalization_performance_history[iteration] = generalization_performance;
      }

      if(reserve_gradient_history)
      {
         results_pointer->gradient_history[iteration] = gradient;                                
      }

      if(reserve_gradient_norm_history)
      {
         results_pointer->gradient_norm_history[iteration] = gradient_norm;
      }

      if(reserve_inverse_Hessian_history)
      {
         results_pointer->inverse_Hessian_history[iteration] = inverse_Hessian;
      }

      // Training history training algorithm

      if(reserve_training_direction_history)
      {
         results_pointer->training_direction_history[iteration] = training_direction;                                
      }

      if(reserve_training_rate_history)
      {
         results_pointer->training_rate_history[iteration] = training_rate;
      }

      if(reserve_elapsed_time_history)
      {
         results_pointer->elapsed_time_history[iteration] = elapsed_time;
      }

      // Stopping Criteria

      if(parameters_increment_norm <= minimum_parameters_increment_norm)
      {
         if(display)
         {
            std::cout << "Iteration " << iteration << ": Minimum parameters increment norm reached.\n"
			          << "Parameters increment norm: " << parameters_increment_norm << std::endl;
         }

         stop_training = true;
      }

      if(iteration != 0 && performance_increase <= minimum_performance_increase)
      {
         if(display)
         {
            std::cout << "Iteration " << iteration << ": Minimum performance increase reached.\n"
                      << "Performance increase: " << performance_increase << std::endl;
         }

         stop_training = true;
      }

      else if(performance <= performance_goal)
      {
         if(display)
         {
            std::cout << "Iteration " << iteration << ": Performance goal reached.\n";
         }

         stop_training = true;
      }

      else if(gradient_norm <= gradient_norm_goal)
      {
         if(display)
         {
            std::cout << "Iteration " << iteration << ": Gradient norm goal reached.\n";  
         }

         stop_training = true;
      }

      else if(generalization_failures >= maximum_generalization_performance_decreases)
      {
         if(display)
         {
            std::cout << "Iteration " << iteration << ": Maximum generalization performance decreases reached.\n"
                      << "Generalization performance decreases: "<< generalization_failures << std::endl;
         }

         stop_training = true;
      }

      else if(iteration == maximum_iterations_number)
      {
         if(display)
         {
            std::cout << "Iteration " << iteration << ": Maximum number of iterations reached.\n";
         }

         stop_training = true;
      }

      else if(elapsed_time >= maximum_time)
      {
         if(display)
         {
            std::cout << "Iteration " << iteration << ": Maximum training time reached.\n";
         }

         stop_training = true;
      }

      if(stop_training)
      {
/*
         results_pointer->final_parameters = parameters;
         results_pointer->final_parameters_norm = parameters_norm;

         results_pointer->final_performance = performance;
         results_pointer->final_generalization_performance = generalization_performance;

         results_pointer->final_gradient = gradient;
         results_pointer->final_gradient_norm = gradient_norm;
   
         results_pointer->final_training_direction = training_direction;
         results_pointer->final_training_rate = training_rate;
         results_pointer->elapsed_time = elapsed_time;

         results_pointer->iterations_number = iteration;

		 results_pointer->resize_training_history(iteration+1);

         if(display)
		 {
            std::cout << "Parameters norm: " << parameters_norm << "\n"
                      << "Performance: " << performance <<  "\n"
                      << "Gradient norm: " << gradient_norm <<  "\n"
                      << performance_functional_pointer->write_information() 
                      << "Training rate: " << training_rate <<  "\n"
                      << "Elapsed time: " << elapsed_time << std::endl; 

            if(generalization_performance != 0)
            {
               std::cout << "Generalization performance: " << generalization_performance << std::endl;
            }
		 }   
*/
         break;
      }
      else if(display && iteration % display_period == 0)
      {
         std::cout << "Iteration " << iteration << ";\n"
                   << "Parameters norm: " << parameters_norm << "\n"
                   << "Performance: " << performance << "\n"
                   << "Gradient norm: " << gradient_norm << "\n"
				   << performance_functional_pointer->write_information() 
                   << "Training rate: " << training_rate << "\n"
                   << "Elapsed time: " << elapsed_time << std::endl; 

         if(generalization_performance != 0)
         {
            std::cout << "Generalization performance: " << generalization_performance << std::endl;
         }
      }

      // Update stuff

      old_parameters = parameters;

      old_performance = performance;

	  old_gradient = gradient;

	  old_inverse_Hessian = inverse_Hessian;
 
	  old_generalization_performance = generalization_performance;

      old_training_rate = training_rate;

      // Set new parameters

      parameters += parameters_increment;

      neural_network_pointer->set_parameters(parameters);
   }

   results_pointer->final_parameters = parameters;
   results_pointer->final_parameters_norm = parameters_norm;

   results_pointer->final_performance = performance;
   results_pointer->final_generalization_performance = generalization_performance;

   results_pointer->final_gradient = gradient;
   results_pointer->final_gradient_norm = gradient_norm;

   results_pointer->final_training_direction = training_direction;
   results_pointer->final_training_rate = training_rate;
   results_pointer->elapsed_time = elapsed_time;

   results_pointer->iterations_number = iteration;

   results_pointer->resize_training_history(iteration+1);

   if(display)
   {
      std::cout << "Parameters norm: " << parameters_norm << "\n"
                << "Performance: " << performance <<  "\n"
                << "Gradient norm: " << gradient_norm <<  "\n"
                << performance_functional_pointer->write_information()
                << "Training rate: " << training_rate <<  "\n"
                << "Elapsed time: " << elapsed_time << std::endl;

      if(generalization_performance != 0)
      {
         std::cout << "Generalization performance: " << generalization_performance << std::endl;
      }
   }

   return(results_pointer);
}


// std::string write_training_algorithm_type(void) const method

std::string QuasiNewtonMethod::write_training_algorithm_type(void) const
{
   return("QUASI_NEWTON_METHOD");
}


// tinyxml2::XMLDocument* to_XML(void) const method

/// Returns a XML-type string representation of this quasi-Newton method object. 
/// It contains the training methods and parameters chosen, as well as 
/// the stopping criteria and other user stuff concerning the quasi-Newton method object.

tinyxml2::XMLDocument* QuasiNewtonMethod::to_XML(void) const
{
   std::ostringstream buffer;

   tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument;

   // Quasi-Newton method

   tinyxml2::XMLElement* root_element = document->NewElement("QuasiNewtonMethod");

   document->InsertFirstChild(root_element);

   tinyxml2::XMLElement* element = NULL;
   tinyxml2::XMLText* text = NULL;

   // Inverse Hessian approximation method
   {
       element = document->NewElement("InverseHessianApproximationMethod");
       root_element->LinkEndChild(element);

       text = document->NewText(write_inverse_Hessian_approximation_method().c_str());
       element->LinkEndChild(text);
   }


   // Training rate algorithm
   {
      tinyxml2::XMLElement* element = document->NewElement("TrainingRateAlgorithm");
      root_element->LinkEndChild(element);

      const tinyxml2::XMLDocument* training_rate_algorithm_document = training_rate_algorithm.to_XML();

      const tinyxml2::XMLElement* training_rate_algorithm_element = training_rate_algorithm_document->FirstChildElement("TrainingRateAlgorithm");

      DeepClone(element, training_rate_algorithm_element, document, NULL);

      delete training_rate_algorithm_document;
   }

   // Warning parameters norm
   {
   element = document->NewElement("WarningParametersNorm");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << warning_parameters_norm;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Warning gradient norm 
   {
   element = document->NewElement("WarningGradientNorm");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << warning_gradient_norm;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Warning training rate 
   {
   element = document->NewElement("WarningTrainingRate");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << warning_training_rate;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Error parameters norm
   {
   element = document->NewElement("ErrorParametersNorm");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << error_parameters_norm;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Error gradient norm 
   {
   element = document->NewElement("ErrorGradientNorm");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << error_gradient_norm;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Error training rate
   {
   element = document->NewElement("ErrorTrainingRate");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << error_training_rate;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Minimum parameters increment norm
   {
   element = document->NewElement("MinimumParametersIncrementNorm");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << minimum_parameters_increment_norm;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Minimum performance increase 
   {
   element = document->NewElement("MinimumPerformanceIncrease");
   root_element->LinkEndChild(element);

   buffer.str(""); 
   buffer << minimum_performance_increase;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Performance goal 
   {
   element = document->NewElement("PerformanceGoal");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << performance_goal;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Gradient norm goal 
   {
   element = document->NewElement("GradientNormGoal");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << gradient_norm_goal;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Maximum generalization performance decreases
   {
   element = document->NewElement("MaximumGeneralizationPerformanceDecreases");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << maximum_generalization_performance_decreases;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Maximum iterations number 
   {
   element = document->NewElement("MaximumIterationsNumber");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << maximum_iterations_number;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Maximum time 
   {
   element = document->NewElement("MaximumTime");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << maximum_time;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Reserve parameters history 
   {
   element = document->NewElement("ReserveParametersHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_parameters_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Reserve parameters norm history 
   {
   element = document->NewElement("ReserveParametersNormHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_parameters_norm_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Reserve performance history 
   {
   element = document->NewElement("ReservePerformanceHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_performance_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Reserve generalization performance history
   {
   element = document->NewElement("ReserveGeneralizationPerformanceHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_generalization_performance_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }


   // Reserve gradient history 
   {
   element = document->NewElement("ReserveGradientHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_gradient_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Reserve gradient norm history 
   {
   element = document->NewElement("ReserveGradientNormHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_gradient_norm_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Reserve inverse Hessian history 
   {
   element = document->NewElement("ReserveInverseHessianHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_inverse_Hessian_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Reserve training direction history 
   {
   element = document->NewElement("ReserveTrainingDirectionHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_training_direction_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Reserve training rate history 
   {
   element = document->NewElement("ReserveTrainingRateHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_training_rate_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Reserve elapsed time history 
   {
   element = document->NewElement("ReserveElapsedTimeHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_elapsed_time_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Reserve generalization performance history 
   {
   element = document->NewElement("ReserveGeneralizationPerformanceHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_generalization_performance_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Display period
   {
   element = document->NewElement("DisplayPeriod");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << display_period;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Display
   {
   element = document->NewElement("Display");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << display;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   return(document);
}


// std::string to_string(void) const method

std::string QuasiNewtonMethod::to_string(void) const
{
    std::ostringstream buffer;

    buffer << "Quasi-Newton method\n";

    return(buffer.str());
}


// Matrix<std::string> to_string_matrix(void) const method

// the most representative

Matrix<std::string> QuasiNewtonMethod::to_string_matrix(void) const
{
    std::ostringstream buffer;

    Vector<std::string> labels;
    Vector<std::string> values;

    // Inverse Hessian approximation method

    labels.push_back("Inverse Hessian approximation method");

    const std::string inverse_Hessian_approximation_method_string = write_inverse_Hessian_approximation_method();

    values.push_back(inverse_Hessian_approximation_method_string);

   // Training rate method

   labels.push_back("Training rate method");

   const std::string training_rate_method = training_rate_algorithm.write_training_rate_method();

   values.push_back(training_rate_method);

   // Training rate tolerance

   labels.push_back("Training rate tolerance");

   buffer.str("");
   buffer << training_rate_algorithm.get_training_rate_tolerance();

   values.push_back(buffer.str());

   // Minimum parameters increment norm

   labels.push_back("Minimum parameters increment norm");

   buffer.str("");
   buffer << minimum_parameters_increment_norm;

   values.push_back(buffer.str());

   // Minimum performance increase

   labels.push_back("Minimum performance increase");

   buffer.str("");
   buffer << minimum_performance_increase;

   values.push_back(buffer.str());

   // Performance goal

   labels.push_back("Performance goal");

   buffer.str("");
   buffer << performance_goal;

   values.push_back(buffer.str());

   // Gradient norm goal

   labels.push_back("Gradient norm goal");

   buffer.str("");
   buffer << gradient_norm_goal;

   values.push_back(buffer.str());

   // Maximum generalization failures

   labels.push_back("Maximum generalization failures");

   buffer.str("");
   buffer << maximum_generalization_performance_decreases;

   values.push_back(buffer.str());

   // Maximum iterations number

   labels.push_back("Maximum iterations number");

   buffer.str("");
   buffer << maximum_iterations_number;

   values.push_back(buffer.str());

   // Maximum time

   labels.push_back("Maximum time");

   buffer.str("");
   buffer << maximum_time;

   values.push_back(buffer.str());

   // Reserve parameters norm history

   labels.push_back("Reserve parameters norm history");

   buffer.str("");
   buffer << reserve_parameters_norm_history;

   values.push_back(buffer.str());

   // Reserve performance history

   labels.push_back("Reserve performance history");

   buffer.str("");
   buffer << reserve_performance_history;

   values.push_back(buffer.str());

   // Reserve gradient norm history

   labels.push_back("Reserve gradient norm history");

   buffer.str("");
   buffer << reserve_gradient_norm_history;

   values.push_back(buffer.str());

   // Reserve generalization performance history

   labels.push_back("Reserve generalization performance history");

   buffer.str("");
   buffer << reserve_generalization_performance_history;

   values.push_back(buffer.str());

   // Reserve training direction norm history

//   labels.push_back("");

//   buffer.str("");
//   buffer << reserve_training_direction_norm_history;

   // Reserve training rate history

//   labels.push_back("");

//   buffer.str("");
//   buffer << reserve_training_rate_history;

//   values.push_back(buffer.str());

   // Reserve elapsed time history

   labels.push_back("Reserve elapsed time history");

   buffer.str("");
   buffer << reserve_elapsed_time_history;

   values.push_back(buffer.str());

   const unsigned rows_number = labels.size();
   const unsigned columns_number = 2;

   Matrix<std::string> string_matrix(rows_number, columns_number);

   string_matrix.set_column(0, labels);
   string_matrix.set_column(1, values);

    return(string_matrix);
}


// void from_XML(const tinyxml2::XMLDocument&) const method

void QuasiNewtonMethod::from_XML(const tinyxml2::XMLDocument& document)
{
   const tinyxml2::XMLElement* root_element = document.FirstChildElement("QuasiNewtonMethod");

   if(!root_element)
   {
       std::ostringstream buffer;

       buffer << "OpenNN Exception: QuasiNewtonMethod class.\n"
              << "void from_XML(const tinyxml2::XMLDocument&) method.\n"
              << "Quasi-Newton method element is NULL.\n";

       throw std::logic_error(buffer.str());
   }

   // Inverse Hessian approximation method
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("InverseHessianApproximationMethod");

       if(element)
       {
          const std::string new_inverse_Hessian_approximation_method = element->GetText();

          try
          {
             set_inverse_Hessian_approximation_method(new_inverse_Hessian_approximation_method);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Inverse Hessian approximation method
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("InverseHessianApproximationMethod");

       if(element)
       {
          const std::string new_inverse_Hessian_approximation_method = element->GetText();

          try
          {
             set_inverse_Hessian_approximation_method(new_inverse_Hessian_approximation_method);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }


   // Training rate algorithm
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("TrainingRateAlgorithm");

       if(element)
       {
         tinyxml2::XMLDocument training_rate_algorithm_document;

         tinyxml2::XMLElement* element_clone = training_rate_algorithm_document.NewElement("TrainingRateAlgorithm");
         training_rate_algorithm_document.InsertFirstChild(element_clone);

         DeepClone(element_clone, element, &training_rate_algorithm_document, NULL);

         training_rate_algorithm.from_XML(training_rate_algorithm_document);
       }
   }

   // Warning parameters norm
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("WarningParametersNorm");

       if(element)
       {
          const double new_warning_parameters_norm = atof(element->GetText());

          try
          {
             set_warning_parameters_norm(new_warning_parameters_norm);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Warning gradient norm 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("WarningGradientNorm");

       if(element)
       {
          const double new_warning_gradient_norm = atof(element->GetText());

          try
          {
             set_warning_gradient_norm(new_warning_gradient_norm);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Warning training rate 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("WarningTrainingRate");

       if(element)
       {
          const double new_warning_training_rate = atof(element->GetText());

          try
          {
             set_warning_training_rate(new_warning_training_rate);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Error parameters norm
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ErrorParametersNorm");

       if(element)
       {
          const double new_error_parameters_norm = atof(element->GetText());

          try
          {
             set_error_parameters_norm(new_error_parameters_norm);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Error gradient norm 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ErrorGradientNorm");

       if(element)
       {
          const double new_error_gradient_norm = atof(element->GetText());

          try
          {
             set_error_gradient_norm(new_error_gradient_norm);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Error training rate
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ErrorTrainingRate");

       if(element)
       {
          const double new_error_training_rate = atof(element->GetText());

          try
          {
             set_error_training_rate(new_error_training_rate);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Minimum parameters increment norm
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("MinimumParametersIncrementNorm");

       if(element)
       {
          const double new_minimum_parameters_increment_norm = atof(element->GetText());

          try
          {
             set_minimum_parameters_increment_norm(new_minimum_parameters_increment_norm);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Minimum performance increase 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("MinimumPerformanceIncrease");

       if(element)
       {
          const double new_minimum_performance_increase = atof(element->GetText());

          try
          {
             set_minimum_performance_increase(new_minimum_performance_increase);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Performance goal 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("PerformanceGoal");

       if(element)
       {
          const double new_performance_goal = atof(element->GetText());

          try
          {
             set_performance_goal(new_performance_goal);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Gradient norm goal 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("GradientNormGoal");

       if(element)
       {
          const double new_gradient_norm_goal = atof(element->GetText());

          try
          {
             set_gradient_norm_goal(new_gradient_norm_goal);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Maximum generalization performance decreases
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("MaximumGeneralizationPerformanceDecreases");

       if(element)
       {
          const unsigned new_maximum_generalization_performance_decreases = atoi(element->GetText());

          try
          {
             set_maximum_generalization_performance_decreases(new_maximum_generalization_performance_decreases);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Maximum iterations number 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("MaximumIterationsNumber");

       if(element)
       {
           const unsigned new_maximum_iterations_number = atoi(element->GetText());

          try
          {
             set_maximum_iterations_number(new_maximum_iterations_number);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Maximum time 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("MaximumTime");

       if(element)
       {
          const double new_maximum_time = atof(element->GetText());

          try
          {
             set_maximum_time(new_maximum_time);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Reserve parameters history
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveParametersHistory");

       if(element)
       {
          const std::string new_reserve_parameters_history = element->GetText();

          try
          {
             set_reserve_parameters_history(new_reserve_parameters_history != "0");
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Reserve parameters norm history 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveParametersNormHistory");

       if(element)
       {
          const std::string new_reserve_parameters_norm_history = element->GetText();

          try
          {
             set_reserve_parameters_norm_history(new_reserve_parameters_norm_history != "0");
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Reserve performance history 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReservePerformanceHistory");

       if(element)
       {
          const std::string new_reserve_performance_history = element->GetText();

          try
          {
             set_reserve_performance_history(new_reserve_performance_history != "0");
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Reserve generalization performance history
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveGeneralizationPerformanceHistory");

       if(element)
       {
          const std::string new_reserve_generalization_performance_history = element->GetText();

          try
          {
             set_reserve_generalization_performance_history(new_reserve_generalization_performance_history != "0");
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Reserve gradient history 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveGradientHistory");

       if(element)
       {
          const std::string new_reserve_gradient_history = element->GetText();

          try
          {
             set_reserve_gradient_history(new_reserve_gradient_history != "0");
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Reserve gradient norm history 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveGradientNormHistory");

       if(element)
       {
          const std::string new_reserve_gradient_norm_history = element->GetText();

          try
          {
             set_reserve_gradient_norm_history(new_reserve_gradient_norm_history != "0");
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Reserve inverse Hessian history 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveInverseHessianHistory");

       if(element)
       {
          const std::string new_reserve_inverse_Hessian_history = element->GetText();

          try
          {
             set_reserve_inverse_Hessian_history(new_reserve_inverse_Hessian_history != "0");
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Reserve training direction history 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveTrainingDirectionHistory");

       if(element)
       {
          const std::string new_reserve_training_direction_history = element->GetText();

          try
          {
             set_reserve_training_direction_history(new_reserve_training_direction_history != "0");
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Reserve training rate history 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveTrainingRateHistory");

       if(element)
       {
          const std::string new_reserve_training_rate_history = element->GetText();

          try
          {
             set_reserve_training_rate_history(new_reserve_training_rate_history != "0");
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Reserve elapsed time history 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveElapsedTimeHistory");

       if(element)
       {
          const std::string new_reserve_elapsed_time_history = element->GetText();

          try
          {
             set_reserve_elapsed_time_history(new_reserve_elapsed_time_history != "0");
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Reserve generalization performance history 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveGeneralizationPerformanceHistory");

       if(element)
       {
          const std::string new_reserve_generalization_performance_history = element->GetText();

          try
          {
             set_reserve_generalization_performance_history(new_reserve_generalization_performance_history != "0");
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Display period
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("DisplayPeriod");

       if(element)
       {
          const unsigned new_display_period = atoi(element->GetText());

          try
          {
             set_display_period(new_display_period);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Display warnings
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("Display");

       if(element)
       {
          const std::string new_display = element->GetText();

          try
          {
             set_display(new_display != "0");
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }
}

}

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

