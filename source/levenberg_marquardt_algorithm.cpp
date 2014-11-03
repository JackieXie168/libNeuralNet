/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   L E V E N B E R G - M A R Q U A R D T   A L G O R I T H M   C L A S S                                      */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// OpenNN includes

#include "levenberg_marquardt_algorithm.h"

namespace OpenNN
{

// DEFAULT CONSTRUCTOR

/// Default constructor. 
/// It creates a Levenberg-Marquardt training algorithm object not associated to any performance functional object. 
/// It also initializes the class members to their default values.

LevenbergMarquardtAlgorithm::LevenbergMarquardtAlgorithm(void)
 : TrainingAlgorithm()
{
   set_default();
}


// PERFORMANCE FUNCTIONAL CONSTRUCTOR

/// Performance functional constructor. 
/// It creates a Levenberg-Marquardt training algorithm object associated associated with a given performance functional object. 
/// It also initializes the class members to their default values.
/// @param new_performance_functional_pointer Pointer to an external performance functional object. 

LevenbergMarquardtAlgorithm::LevenbergMarquardtAlgorithm(PerformanceFunctional* new_performance_functional_pointer)
 : TrainingAlgorithm(new_performance_functional_pointer)
{
   set_default();
}


// XML CONSTRUCTOR

/// XML Constructor.
/// Creates a Levenberg-Marquardt algorithm object, and loads its members from a XML document. 
/// @param document TinyXML document containing the Levenberg-Marquardt algorithm data.

LevenbergMarquardtAlgorithm::LevenbergMarquardtAlgorithm(const tinyxml2::XMLDocument& document)
 : TrainingAlgorithm(document)
{
   set_default();

   from_XML(document);
}


// DESTRUCTOR

/// Destructor.
/// This destructor does not delete any object. 

LevenbergMarquardtAlgorithm::~LevenbergMarquardtAlgorithm(void)
{
}


// const double& get_warning_parameters_norm(void) const method

/// Returns the minimum value for the norm of the parameters vector at wich a warning message is 
/// written to the screen. 

const double& LevenbergMarquardtAlgorithm::get_warning_parameters_norm(void) const
{
   return(warning_parameters_norm);       
}


// const double& get_warning_gradient_norm(void) const method

/// Returns the minimum value for the norm of the gradient vector at wich a warning message is written
/// to the screen. 

const double& LevenbergMarquardtAlgorithm::get_warning_gradient_norm(void) const
{
   return(warning_gradient_norm);       
}


// const double& get_error_parameters_norm(void) const method

/// Returns the value for the norm of the parameters vector at wich an error message is 
/// written to the screen and the program exits. 

const double& LevenbergMarquardtAlgorithm::get_error_parameters_norm(void) const
{
   return(error_parameters_norm);
}


// const double& get_error_gradient_norm(void) const method

/// Returns the value for the norm of the gradient vector at wich an error message is written
/// to the screen and the program exits. 

const double& LevenbergMarquardtAlgorithm::get_error_gradient_norm(void) const
{
   return(error_gradient_norm);
}


// const double& get_minimum_parameters_increment_norm(void) const method

/// Returns the minimum norm of the parameter increment vector used as a stopping criteria when training. 

const double& LevenbergMarquardtAlgorithm::get_minimum_parameters_increment_norm(void) const
{
   return(minimum_parameters_increment_norm);
}


// const double& get_minimum_performance_increase(void) const method

/// Returns the minimum performance improvement during training.  

const double& LevenbergMarquardtAlgorithm::get_minimum_performance_increase(void) const
{
   return(minimum_performance_increase);
}


// const double& get_performance_goal(void) const method

/// Returns the goal value for the performance. 
/// This is used as a stopping criterion when training a neural network.

const double& LevenbergMarquardtAlgorithm::get_performance_goal(void) const
{
   return(performance_goal);
}


// const double& get_gradient_norm_goal(void) const method

/// Returns the goal value for the norm of the performance function gradient.
/// This is used as a stopping criterion when training a neural network.

const double& LevenbergMarquardtAlgorithm::get_gradient_norm_goal(void) const
{
   return(gradient_norm_goal);
}


// const unsigned& get_maximum_generalization_performance_decreases(void) const method

/// Returns the maximum number of generalization failures during the training process. 

const unsigned& LevenbergMarquardtAlgorithm::get_maximum_generalization_performance_decreases(void) const
{
   return(maximum_generalization_performance_decreases);
}


// const unsigned& get_maximum_iterations_number(void) const method

/// Returns the maximum number of iterations for training.

const unsigned& LevenbergMarquardtAlgorithm::get_maximum_iterations_number(void) const
{
   return(maximum_iterations_number);
}


// const double& get_maximum_time(void) const method

/// Returns the maximum training time.  

const double& LevenbergMarquardtAlgorithm::get_maximum_time(void) const
{
   return(maximum_time);
}


// const bool& get_reserve_parameters_history(void) const method

/// Returns true if the parameters history matrix is to be reserved, and false otherwise.

const bool& LevenbergMarquardtAlgorithm::get_reserve_parameters_history(void) const
{
   return(reserve_parameters_history);     
}


// const bool& get_reserve_parameters_norm_history(void) const method 

/// Returns true if the parameters norm history vector is to be reserved, and false otherwise.

const bool& LevenbergMarquardtAlgorithm::get_reserve_parameters_norm_history(void) const
{
   return(reserve_parameters_norm_history);     
}


// const bool& get_reserve_performance_history(void) const method

/// Returns true if the performance history vector is to be reserved, and false otherwise.

const bool& LevenbergMarquardtAlgorithm::get_reserve_performance_history(void) const
{
   return(reserve_performance_history);
}


// const bool& get_reserve_gradient_history(void) const method

/// Returns true if the gradient history vector of vectors is to be reserved, and false otherwise.

const bool& LevenbergMarquardtAlgorithm::get_reserve_gradient_history(void) const
{
   return(reserve_gradient_history);     
}


// const bool& get_reserve_gradient_norm_history(void) const method

/// Returns true if the gradient norm history vector is to be reserved, and false otherwise.

const bool& LevenbergMarquardtAlgorithm::get_reserve_gradient_norm_history(void) const
{
   return(reserve_gradient_norm_history);     
}


// const bool& get_reserve_Hessian_approximation_history(void) const method

/// Returns true if the history of the Hessian approximations is to be reserved,
/// and false otherwise.

const bool& LevenbergMarquardtAlgorithm::get_reserve_Hessian_approximation_history(void) const
{
   return(reserve_Hessian_approximation_history);
}


// const bool& get_reserve_elapsed_time_history(void) const method

/// Returns true if the elapsed time history vector is to be reserved, and false otherwise.

const bool& LevenbergMarquardtAlgorithm::get_reserve_elapsed_time_history(void) const
{
   return(reserve_elapsed_time_history);     
}


// const bool& get_reserve_generalization_performance_history(void) const method

/// Returns true if the Generalization performance history vector is to be reserved, and false otherwise.

const bool& LevenbergMarquardtAlgorithm::get_reserve_generalization_performance_history(void) const
{
   return(reserve_generalization_performance_history);
}


// const unsigned& get_display_period(void) const method

/// Returns the number of iterations between the training showing progress. 

const unsigned& LevenbergMarquardtAlgorithm::get_display_period(void) const
{
   return(display_period);
}


// const double& get_damping_parameter(void) const method

/// Returns the damping parameter for the Hessian approximation. 

const double& LevenbergMarquardtAlgorithm::get_damping_parameter(void) const
{
   return(damping_parameter);
}


// const double& get_damping_parameter_factor(void) const method

/// Returns the damping parameter factor (beta in the User's Guide) for the Hessian approximation. 

const double& LevenbergMarquardtAlgorithm::get_damping_parameter_factor(void) const
{
   return(damping_parameter_factor);
}


// const double& get_minimum_damping_parameter(void) const method

/// Returns the minimum damping parameter allowed in the algorithm. 

const double& LevenbergMarquardtAlgorithm::get_minimum_damping_parameter(void) const
{
   return(minimum_damping_parameter);
}


// const double& get_maximum_damping_parameter(void) const method

/// Returns the maximum damping parameter allowed in the algorithm. 

const double& LevenbergMarquardtAlgorithm::get_maximum_damping_parameter(void) const
{
   return(maximum_damping_parameter);
}


// const bool& get_reserve_damping_parameter_history(void) const method

/// Returns true if the damping parameter history vector is to be reserved, and false otherwise.

const bool& LevenbergMarquardtAlgorithm::get_reserve_damping_parameter_history(void) const
{
   return(reserve_damping_parameter_history);
}


// const Vector<double> const get_damping_parameter_history(void) const method

/// Returns a vector containing the damping parameter history over the training iterations.

const Vector<double>& LevenbergMarquardtAlgorithm::get_damping_parameter_history(void) const
{
   return(damping_parameter_history);
}


// void set_default(void) method

/// Sets the following default values for the Levenberg-Marquardt algorithm:
/// Training parameters:
/// <ul>
/// <li> Levenberg-Marquardt parameter: 0.001.
/// </ul>
/// Stopping criteria:
/// <ul> 
/// <li> Performance goal: 0.0.
/// <li> Gradient approximation norm goal: 0.0.
/// <li> Maximum training time: 1.0e6.
/// <li> Maximum number of iterations: 100. 
/// </ul> 
/// User stuff: 
/// <ul>
/// <li> Iterations between showing progress: 10.
/// </ul>

void LevenbergMarquardtAlgorithm::set_default(void)
{
   // TRAINING PARAMETERS

   warning_parameters_norm = 1.0e6;
   warning_gradient_norm = 1.0e6;   

   error_parameters_norm = 1.0e9;
   error_gradient_norm = 1.0e9;

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

   reserve_Hessian_approximation_history = false;

   reserve_elapsed_time_history = false;

   // UTILITIES

   display = true;
   display_period = 10;

   // Training parameters

   damping_parameter = 1.0e-3;

   damping_parameter_factor = 10.0;

   minimum_damping_parameter = 1.0e-6;
   maximum_damping_parameter = 1.0e6;

   reserve_damping_parameter_history = false;
}


// void set_damping_parameter(const double&) method

/// Sets a new damping parameter (lambda in the User's Guide) for the Hessian approximation. 
/// @param new_damping_parameter Damping parameter value. 

void LevenbergMarquardtAlgorithm::set_damping_parameter(const double& new_damping_parameter)
{
   if(new_damping_parameter <= minimum_damping_parameter)
   {
      damping_parameter = minimum_damping_parameter;
   }
   else if(new_damping_parameter >= maximum_damping_parameter)
   {
      damping_parameter = maximum_damping_parameter;
   }
   else
   {
      damping_parameter = new_damping_parameter;
   }
}


// void set_damping_parameter_factor(const double&) method

/// Sets a new damping parameter factor (beta in the User's Guide) for the Hessian approximation. 
/// @param new_damping_parameter_factor Damping parameter factor value. 

void LevenbergMarquardtAlgorithm::set_damping_parameter_factor(const double& new_damping_parameter_factor)
{
   #ifndef NDEBUG 

   if(new_damping_parameter_factor <= 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: LevenbergMarquardtAlgorithm class." << std::endl
             << "void set_damping_parameter_factor(const double&) method." << std::endl
             << "Damping parameter factor must be greater than zero." << std::endl;

      throw std::logic_error(buffer.str());	  
   }

   #endif

   damping_parameter_factor = new_damping_parameter_factor;
}


// void set_minimum_damping_parameter(const double&) method

/// Sets a new minimum damping parameter allowed in the algorithm. 
/// @param new_minimum_damping_parameter Minimum damping parameter value. 

void LevenbergMarquardtAlgorithm::set_minimum_damping_parameter(const double& new_minimum_damping_parameter)
{
   #ifndef NDEBUG 

   if(new_minimum_damping_parameter <= 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: LevenbergMarquardtAlgorithm class." << std::endl
             << "void set_minimum_damping_parameter(const double&) method." << std::endl
             << "Minimum damping parameter must be greater than zero." << std::endl;

      throw std::logic_error(buffer.str());	  
   }

   #endif

   minimum_damping_parameter = new_minimum_damping_parameter;
}


// void set_maximum_damping_parameter(const double&) method

/// Sets a new maximum damping parameter allowed in the algorithm. 
/// @param new_maximum_damping_parameter Maximum damping parameter value. 

void LevenbergMarquardtAlgorithm::set_maximum_damping_parameter(const double& new_maximum_damping_parameter)
{
   #ifndef NDEBUG 

   if(new_maximum_damping_parameter <= 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: LevenbergMarquardtAlgorithm class." << std::endl
             << "void set_maximum_damping_parameter(const double&) method." << std::endl
             << "Maximum damping parameter must be greater than zero." << std::endl;

      throw std::logic_error(buffer.str());	  
   }

   #endif

   maximum_damping_parameter = new_maximum_damping_parameter;
}


// void set_reserve_damping_parameter_history(bool) method

/// Makes the damping parameter history vector to be reseved or not in memory.
/// @param new_reserve_damping_parameter_history True if the damping parameter history vector is to be reserved, false otherwise.

void LevenbergMarquardtAlgorithm::set_reserve_damping_parameter_history(const bool& new_reserve_damping_parameter_history)
{
   reserve_damping_parameter_history = new_reserve_damping_parameter_history;
}


// void set_warning_parameters_norm(const double&) method

/// Sets a new value for the parameters vector norm at which a warning message is written to the 
/// screen. 
/// @param new_warning_parameters_norm Warning norm of parameters vector value. 

void LevenbergMarquardtAlgorithm::set_warning_parameters_norm(const double& new_warning_parameters_norm)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_warning_parameters_norm < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: TrainingAlgorithm class.\n"
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

void LevenbergMarquardtAlgorithm::set_warning_gradient_norm(const double& new_warning_gradient_norm)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_warning_gradient_norm < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: TrainingAlgorithm class.\n"
             << "void set_warning_gradient_norm(const double&) method.\n"
             << "Warning gradient norm must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set warning gradient norm

   warning_gradient_norm = new_warning_gradient_norm;     
}


// void set_error_parameters_norm(const double&) method

/// Sets a new value for the parameters vector norm at which an error message is written to the 
/// screen and the program exits. 
/// @param new_error_parameters_norm Error norm of parameters vector value. 

void LevenbergMarquardtAlgorithm::set_error_parameters_norm(const double& new_error_parameters_norm)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_error_parameters_norm < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: TrainingAlgorithm class.\n"
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

void LevenbergMarquardtAlgorithm::set_error_gradient_norm(const double& new_error_gradient_norm)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_error_gradient_norm < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: TrainingAlgorithm class.\n"
             << "void set_error_gradient_norm(const double&) method.\n"
             << "Error gradient norm must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set error gradient norm

   error_gradient_norm = new_error_gradient_norm;
}


// void set_minimum_parameters_increment_norm(const double&) method

/// Sets a new value for the minimum parameters increment norm stopping criterion. 
/// @param new_minimum_parameters_increment_norm Value of norm of parameters increment norm used to stop training. 

void LevenbergMarquardtAlgorithm::set_minimum_parameters_increment_norm(const double& new_minimum_parameters_increment_norm)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_minimum_parameters_increment_norm < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: TrainingAlgorithm class.\n"
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

void LevenbergMarquardtAlgorithm::set_minimum_performance_increase(const double& new_minimum_performance_increase)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_minimum_performance_increase < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: TrainingAlgorithm class.\n"
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
/// This is used as a stopping criterion when training a neural network.
/// @param new_performance_goal Goal value for the performance.

void LevenbergMarquardtAlgorithm::set_performance_goal(const double& new_performance_goal)
{
   performance_goal = new_performance_goal;
}


// void set_gradient_norm_goal(const double&) method

/// Sets a new the goal value for the norm of the performance function gradient.
/// This is used as a stopping criterion when training a neural network.
/// @param new_gradient_norm_goal Goal value for the norm of the performance function gradient.

void LevenbergMarquardtAlgorithm::set_gradient_norm_goal(const double& new_gradient_norm_goal)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_gradient_norm_goal < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: TrainingAlgorithm class.\n"
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

void LevenbergMarquardtAlgorithm::set_maximum_generalization_performance_decreases(const unsigned& new_maximum_generalization_performance_decreases)
{
   maximum_generalization_performance_decreases = new_maximum_generalization_performance_decreases;
}


// void set_maximum_iterations_number(unsigned) method

/// Sets a maximum number of iterations for training.
/// @param new_maximum_iterations_number Maximum number of iterations for training.

void LevenbergMarquardtAlgorithm::set_maximum_iterations_number(const unsigned& new_maximum_iterations_number)
{
   maximum_iterations_number = new_maximum_iterations_number;
}


// void set_maximum_time(const double&) method

/// Sets a new maximum training time.  
/// @param new_maximum_time Maximum training time.

void LevenbergMarquardtAlgorithm::set_maximum_time(const double& new_maximum_time)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_maximum_time < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: TrainingAlgorithm class.\n"
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

void LevenbergMarquardtAlgorithm::set_reserve_parameters_history(const bool& new_reserve_parameters_history)
{
   reserve_parameters_history = new_reserve_parameters_history;     
}


// void set_reserve_parameters_norm_history(bool) method

/// Makes the parameters norm history vector to be reseved or not in memory.
/// @param new_reserve_parameters_norm_history True if the parameters norm history vector is to be reserved, false otherwise.

void LevenbergMarquardtAlgorithm::set_reserve_parameters_norm_history(const bool& new_reserve_parameters_norm_history)
{
   reserve_parameters_norm_history = new_reserve_parameters_norm_history;     
}


// void set_reserve_performance_history(bool) method

/// Makes the performance history vector to be reseved or not in memory.
/// @param new_reserve_performance_history True if the performance history vector is to be reserved, false otherwise.

void LevenbergMarquardtAlgorithm::set_reserve_performance_history(const bool& new_reserve_performance_history)
{
   reserve_performance_history = new_reserve_performance_history;
}


// void set_reserve_gradient_history(bool) method

/// Makes the gradient history vector of vectors to be reseved or not in memory.
/// @param new_reserve_gradient_history True if the gradient history matrix is to be reserved, false otherwise.

void LevenbergMarquardtAlgorithm::set_reserve_gradient_history(const bool& new_reserve_gradient_history)
{
   reserve_gradient_history = new_reserve_gradient_history;    
}


// void set_reserve_gradient_norm_history(bool) method

/// Makes the gradient norm history vector to be reseved or not in memory.
/// @param new_reserve_gradient_norm_history True if the gradient norm history matrix is to be reserved, false 
/// otherwise.

void LevenbergMarquardtAlgorithm::set_reserve_gradient_norm_history(const bool& new_reserve_gradient_norm_history)
{
   reserve_gradient_norm_history = new_reserve_gradient_norm_history;     
}


// void set_reserve_Hessian_approximation_history(bool) method

/// Sets the history of the Hessian approximation to be reserved or not in memory.
/// This is a vector of matrices. 
/// @param new_reserve_Hessian_approximation_history True if the Hessian approximation history is to be reserved, false otherwise.

void LevenbergMarquardtAlgorithm::set_reserve_Hessian_approximation_history(const bool& new_reserve_Hessian_approximation_history)
{
   reserve_Hessian_approximation_history = new_reserve_Hessian_approximation_history;
}


// void set_reserve_elapsed_time_history(bool) method

/// Makes the elapsed time over the iterations to be reseved or not in memory. This is a vector.
/// @param new_reserve_elapsed_time_history True if the elapsed time history vector is to be reserved, false 
/// otherwise.

void LevenbergMarquardtAlgorithm::set_reserve_elapsed_time_history(const bool& new_reserve_elapsed_time_history)
{
   reserve_elapsed_time_history = new_reserve_elapsed_time_history;     
}


// void set_reserve_generalization_performance_history(bool) method

/// Makes the Generalization performance history to be reserved or not in memory.
/// This is a vector. 
/// @param new_reserve_generalization_performance_history True if the Generalization performance history is to be reserved, false otherwise.

void LevenbergMarquardtAlgorithm::set_reserve_generalization_performance_history(const bool& new_reserve_generalization_performance_history)
{
   reserve_generalization_performance_history = new_reserve_generalization_performance_history;
}


// void set_display_period(unsigned) method

/// Sets a new number of iterations between the training showing progress. 
/// @param new_display_period
/// Number of iterations between the training showing progress. 

void LevenbergMarquardtAlgorithm::set_display_period(const unsigned& new_display_period)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 
     
   if(new_display_period <= 0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: TrainingAlgorithm class.\n"
             << "void set_display_period(const double&) method.\n"
             << "First training rate must be greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   display_period = new_display_period;
}


// void check(void) const method

/// Checks that the Levenberg-Marquard object is ok for training.  
/// In particular, it checks that:
/// <ul>
/// <li> The performance functional pointer associated to the training algorithm is not NULL,
/// <li> The neural network associated to that performance functional is neither NULL.
/// <li> The data set associated to that performance functional is neither NULL.
/// </ul>
/// If that checkings are not hold, an exception is thrown. 

void LevenbergMarquardtAlgorithm::check(void) const
{
   std::ostringstream buffer;

   if(!performance_functional_pointer)
   {
      buffer << "OpenNN Exception: LevenbergMarquardtAlgorithm class.\n"
             << "void check(void) const method.\n"
             << "Pointer to performance functional is NULL.\n";

      throw std::logic_error(buffer.str());	  
   }

   const DataSet* data_set_pointer = performance_functional_pointer->get_data_set_pointer();

   if(!data_set_pointer)
   {
      buffer << "OpenNN Exception: LevenbergMarquardtAlgorithm class." << std::endl
             << "void check(void) const method.\n"
             << "The performance funcional has no data set." << std::endl;

      throw std::logic_error(buffer.str());	  
   }

   const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   if(!neural_network_pointer)
   {
      buffer << "OpenNN Exception: LevenbergMarquardtAlgorithm class." << std::endl
             << "void check(void) const method.\n"
             << "Pointer to neural network is NULL." << std::endl;

      throw std::logic_error(buffer.str());	  
   }

}


// double calculate_performance(const Vector<double>&) const method

/// Evaluates the performance function from the evaluation of the terms function.
/// @param terms Vector of performance terms.

double LevenbergMarquardtAlgorithm::calculate_performance(const Vector<double>& terms) const
{           
    return((terms*terms).calculate_sum());
}


// Vector<double> calculate_gradient(const Vector<double>&, const Matrix<double>&) const method

/// Returns the exact gradient vector of the performance function as a function of the terms vector and the terms Jacobian matrix.
/// @param terms Vector with the performance terms values.
/// @param terms_Jacobian Jacobian matrix of the performance terms function.

Vector<double> LevenbergMarquardtAlgorithm
::calculate_gradient(const Vector<double>& terms, const Matrix<double>& terms_Jacobian) const
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   std::ostringstream buffer;

   const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   const unsigned columns_number = terms_Jacobian.get_columns_number();

   if(columns_number != parameters_number)
   {
      buffer << "OpenNN Exception: LevenbergMarquardtAlgorithm class." << std::endl
             << "Vector<double> calculate_gradient(const Vector<double>&, const Matrix<double>&) const method." << std::endl
             << "Number of columns in terms Jacobian must be equal to number of parameters." << std::endl;

      throw std::logic_error(buffer.str());	  
   }

   #endif

   return(terms_Jacobian.calculate_transpose().dot(terms)*2.0);
}


// Matrix<double> calculate_Hessian_approximation(const Matrix<double>&) const method

/// Returns an approximation of the Hessian matrix of the performance function
/// as a function of the performance terms Jacobian.
/// @param terms_Jacobian Jacobian matrix of the terms function.

Matrix<double> LevenbergMarquardtAlgorithm::calculate_Hessian_approximation(const Matrix<double>& terms_Jacobian) const
{
   // Control sentence (if debug)

   const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   #ifndef NDEBUG

   std::ostringstream buffer;

   const unsigned columns_number = terms_Jacobian.get_columns_number();

   if(columns_number != parameters_number)
   {
      buffer << "OpenNN Exception: LevenbergMarquardtAlgorithm class." << std::endl
             << "Matrix<double> calculate_Hessian_approximation(const Matrix<double>&) const method." << std::endl
             << "Number of columns in terms Jacobian must be equal to number of parameters." << std::endl;

      throw std::logic_error(buffer.str());
   }

   #endif

   Matrix<double> identity(parameters_number, parameters_number);

   identity.initialize_identity();

   return(terms_Jacobian.calculate_transpose().dot(terms_Jacobian)*2.0 + identity*damping_parameter);
}


// void resize_training_history(const unsigned&) method

/// Resizes all the training history variables. 
/// @param new_size Size of training history variables. 

void LevenbergMarquardtAlgorithm::LevenbergMarquardtAlgorithmResults::resize_training_history(const unsigned& new_size)
{
    // Control sentence (if debug)

    #ifndef NDEBUG

    if(Levenberg_Marquardt_algorithm_pointer == NULL)
    {
       std::ostringstream buffer;

       buffer << "OpenNN Exception: LevenbergMarquardtAlgorithmResults structure.\n"
              << "void resize_training_history(const unsigned&) method.\n"
              << "Levenberg-Marquardt algorithm pointer is NULL.\n";

       throw std::logic_error(buffer.str());
    }

    #endif

    if(Levenberg_Marquardt_algorithm_pointer->get_reserve_parameters_history())
    {
        parameters_history.resize(new_size);
    }

    if(Levenberg_Marquardt_algorithm_pointer->get_reserve_parameters_norm_history())
    {
        parameters_norm_history.resize(new_size);
    }

    if(Levenberg_Marquardt_algorithm_pointer->get_reserve_performance_history())
    {
        performance_history.resize(new_size);
    }

    if(Levenberg_Marquardt_algorithm_pointer->get_reserve_generalization_performance_history())
    {
        generalization_performance_history.resize(new_size);
    }

    if(Levenberg_Marquardt_algorithm_pointer->get_reserve_gradient_history())
    {
        gradient_history.resize(new_size);
    }

    if(Levenberg_Marquardt_algorithm_pointer->get_reserve_gradient_norm_history())
    {
        gradient_norm_history.resize(new_size);
    }

    if(Levenberg_Marquardt_algorithm_pointer->get_reserve_Hessian_approximation_history())
    {
        Hessian_approximation_history.resize(new_size);
    }

    if(Levenberg_Marquardt_algorithm_pointer->get_reserve_damping_parameter_history())
    {
        damping_parameter_history.resize(new_size);
    }

    if(Levenberg_Marquardt_algorithm_pointer->get_reserve_elapsed_time_history())
    {
        elapsed_time_history.resize(new_size);
    }
}


// std::string to_string(void) const method

/// Returns a string representation of the current Levenberg-Marquardt algorithm results structure. 

std::string LevenbergMarquardtAlgorithm::LevenbergMarquardtAlgorithmResults::to_string(void) const
{
   std::ostringstream buffer;

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

   // Hessian approximation history

   if(!Hessian_approximation_history.empty())
   {
      if(!Hessian_approximation_history[0].empty())
      {
          buffer << "% Hessian approximation history:\n"
                 << Hessian_approximation_history << "\n";
	  }
   }

   // Damping parameter history

   if(!damping_parameter_history.empty())
   {
       buffer << "% Damping parameter history:\n"
              << damping_parameter_history << "\n"; 
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

Matrix<std::string> LevenbergMarquardtAlgorithm::LevenbergMarquardtAlgorithmResults::write_final_results(const unsigned& precision) const
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

   const PerformanceFunctional* performance_functional_pointer = Levenberg_Marquardt_algorithm_pointer->get_performance_functional_pointer();

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


// LevenbergMarquardtAlgorithmResults* perform_training(void) method

/// Trains a neural network with an associated performance functional according to the Levenberg-Marquardt algorithm.
/// Training occurs according to the training parameters.

LevenbergMarquardtAlgorithm::LevenbergMarquardtAlgorithmResults* LevenbergMarquardtAlgorithm::perform_training(void)
{
    std::ostringstream buffer;

   // Control sentence

   #ifndef NDEBUG 
  
   check();

   #endif

   // Start training

   if(display)
   {
      std::cout << "Training with Levenberg-Marquardt algorithm...\n";
   }

   LevenbergMarquardtAlgorithmResults* results_pointer = new LevenbergMarquardtAlgorithmResults(this);

   results_pointer->resize_training_history(1+maximum_iterations_number);

   // Neural network stuff

   NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   Vector<double> parameters = neural_network_pointer->arrange_parameters();

   double parameters_norm;

   // Data set stuff

   const DataSet* data_set_pointer = performance_functional_pointer->get_data_set_pointer();

   const Instances& instances = data_set_pointer->get_instances();

   const unsigned training_instances_number = instances.count_training_instances_number();

   // Performance functional stuff

   double performance = 0.0;
   double old_performance = 0.0;
   double performance_increase = 0.0;

   double generalization_performance = 0.0;
   double old_generalization_performance = 0.0;

   unsigned generalization_failures = 0;

   Vector<double> terms(training_instances_number);
   Matrix<double> terms_Jacobian(training_instances_number, parameters_number);

   Vector<double> gradient(parameters_number);

   double gradient_norm;

   Matrix<double> JacobianT_dot_Jacobian(parameters_number, parameters_number);

   Matrix<double> Hessian_approximation(parameters_number, parameters_number);

   // Training strategy stuff

   Vector<double> parameters_increment(parameters_number);
   double parameters_increment_norm;

   Matrix<double> identity(parameters_number, parameters_number);
   identity.initialize_identity();

   bool stop_training = false;

   time_t beginning_time, current_time;
   time(&beginning_time);
   double elapsed_time;

   // Main loop

   for(unsigned iteration = 0; iteration <= maximum_iterations_number; iteration++)
   {
      // Neural network

      parameters_norm = parameters.calculate_norm();

      if(display && parameters_norm >= warning_parameters_norm)
      {
         std::cout << "OpenNN Warning: Parameters norm is " << parameters_norm << "." << std::endl;          
      }

      // Performance functional 

      terms = performance_functional_pointer->calculate_terms();

      performance = calculate_performance(terms);//*performance_terms).calculate_sum()/2.0;

      terms_Jacobian = performance_functional_pointer->calculate_terms_Jacobian();

      gradient = calculate_gradient(terms, terms_Jacobian);

      gradient_norm = gradient.calculate_norm();

      if(display && gradient_norm >= warning_gradient_norm)
      {
         std::cout << "OpenNN Warning: Gradient norm is " << gradient_norm << "." << std::endl;          
      }

      JacobianT_dot_Jacobian = terms_Jacobian.calculate_transpose().dot(terms_Jacobian);

      do
      {
         Hessian_approximation = (JacobianT_dot_Jacobian + identity*damping_parameter);

         parameters_increment = gradient*(-1.0);         

         LinearAlgebraicEquations::perform_Gauss_Jordan_elimination(Hessian_approximation, parameters_increment);

         const double new_performance = performance_functional_pointer->calculate_performance(parameters+parameters_increment);

         if(new_performance <= performance) // succesfull step
         {
             set_damping_parameter(damping_parameter/damping_parameter_factor);

             parameters += parameters_increment;

             performance = new_performance;

            break;
         }
         else
         {
             set_damping_parameter(damping_parameter*damping_parameter_factor);
         }
      }while(damping_parameter < maximum_damping_parameter);

      parameters_increment_norm = parameters_increment.calculate_norm();

      if(iteration == 0)
      {
         performance_increase = 0.0;
      }
      else
      {
         performance_increase = old_performance - performance;
      }

      generalization_performance = performance_functional_pointer->calculate_generalization_performance();

      if(iteration != 0 && generalization_performance > old_generalization_performance)
      {
         generalization_failures++;
      }
      
      // Elapsed time

      time(&current_time);
      elapsed_time = difftime(current_time, beginning_time);

      // Training history neural network

      if(reserve_parameters_history)
      {
         results_pointer->parameters_history[iteration] = parameters;
      }

      if(reserve_parameters_norm_history)
      {
         results_pointer->parameters_norm_history[iteration] = parameters_norm;
      }

      // Training history performance functional

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

      if(reserve_Hessian_approximation_history)
      {
         results_pointer->Hessian_approximation_history[iteration] = Hessian_approximation; // as computed by linear algebraic equations object
      }

      // Training history training algorithm

      if(reserve_damping_parameter_history)
      {
         results_pointer->damping_parameter_history[iteration] = damping_parameter;
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

      else if(performance <= performance_goal)
      {
         if(display)
         {
            std::cout << "Iteration " << iteration << ": Performance goal reached.\n";
         }

         stop_training = true;
      }

      else if(iteration != 0 && performance_increase <= minimum_performance_increase)
      {
         if(display)
         {
             std::cout << "Iteration " << iteration << ": Minimum performance increase (" << minimum_performance_increase << ") reached.\n"
                      << "Performance increase: " << performance_increase << std::endl;
         }

         stop_training = true;
      }

      else if(gradient_norm <= gradient_norm_goal)
      {
         if(display)
         {
            std::cout << "Iteration " << iteration << ": Gradient norm goal reached." << std::endl;  
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
            std::cout << "Iteration " << iteration << ": Maximum number of iterations reached." << std::endl;
         }

         stop_training = true;
      }

      else if(elapsed_time >= maximum_time)
      {
         if(display)
         {
            std::cout << "Iteration " << iteration << ": Maximum training time reached." << std::endl;
         }

         stop_training = true;
      }

	  if(stop_training)
      {
          if(display)
          {
             std::cout << "Parameters norm: " << parameters_norm << "\n"
                       << "performance: " << performance << "\n"
                       << "Gradient norm: " << gradient_norm << "\n"
                       << performance_functional_pointer->write_information()
                       << "Damping parameter: " << damping_parameter << "\n"
                       << "Elapsed time: " << elapsed_time << std::endl;

             if(generalization_performance != 0)
             {
                std::cout << "Generalization performance: " << generalization_performance << std::endl;
             }
          }

          neural_network_pointer->set_parameters(parameters);

          results_pointer->resize_training_history(1+iteration);

         results_pointer->final_parameters = parameters;
         results_pointer->final_parameters_norm = parameters_norm;

         results_pointer->final_performance = performance;
         results_pointer->final_generalization_performance = generalization_performance;

         results_pointer->final_gradient = gradient;
         results_pointer->final_gradient_norm = gradient_norm;
   
         results_pointer->elapsed_time = elapsed_time;

         results_pointer->iterations_number = iteration;

         break;
      }
      else if(display && iteration % display_period == 0)
      {
         std::cout << "Iteration " << iteration << ";\n" 
                   << "Parameters norm: " << parameters_norm << "\n"
                   << "performance: " << performance << "\n"
                   << "Gradient norm: " << gradient_norm << "\n"
                   << performance_functional_pointer->write_information()
                   << "Damping parameter: " << damping_parameter << "\n"
                   << "Elapsed time: " << elapsed_time << std::endl; 

         if(generalization_performance != 0)
         {
            std::cout << "Generalization performance: " << generalization_performance << std::endl;
         }

      }

      // Update stuff

      old_performance = performance;
      old_generalization_performance = generalization_performance;

      // Set new parameters

      neural_network_pointer->set_parameters(parameters);
   } 

   return(results_pointer);
}


// void set_reserve_all_training_history(const bool&) method

void LevenbergMarquardtAlgorithm::set_reserve_all_training_history(const bool&)
{
   reserve_parameters_history = true;
   reserve_parameters_norm_history = true;

   reserve_performance_history = true;
   reserve_generalization_performance_history = true;

   reserve_gradient_history = true;
   reserve_gradient_norm_history = true;
   reserve_Hessian_approximation_history = true;

   reserve_damping_parameter_history = true;
   reserve_elapsed_time_history = true;
}


// std::string write_training_algorithm_type(void) const method

std::string LevenbergMarquardtAlgorithm::write_training_algorithm_type(void) const
{
   return("LEVENBERG_MARQUARDT_ALGORITHM");
}


// Matrix<std::string> to_string_matrix(void) const method

// the most representative

Matrix<std::string> LevenbergMarquardtAlgorithm::to_string_matrix(void) const
{
    std::ostringstream buffer;

    Vector<std::string> labels;
    Vector<std::string> values;

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


// tinyxml2::XMLDocument* to_XML(void) const method

tinyxml2::XMLDocument* LevenbergMarquardtAlgorithm::to_XML(void) const
{
   std::ostringstream buffer;

   tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument;

   // Training algorithm

   tinyxml2::XMLElement* root_element = document->NewElement("LevenbergMarquardtAlgorithm");
   document->InsertFirstChild(root_element);

   tinyxml2::XMLElement* element = NULL;
   tinyxml2::XMLText* text = NULL;

   // Damping parameter

   element = document->NewElement("DampingParameter");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << damping_parameter;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Minimum damping parameter.

   element = document->NewElement("MinimumDampingParameter");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << minimum_damping_parameter;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Maximum damping parameter.

   element = document->NewElement("MaximumDampingParameter");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << maximum_damping_parameter;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Damping paramterer factor.

   element = document->NewElement("DampingParameterFactor");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << damping_parameter_factor;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Warning parameters norm

   element = document->NewElement("WarningParametersNorm");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << warning_parameters_norm;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Warning gradient norm 

   element = document->NewElement("WarningGradientNorm");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << warning_gradient_norm;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Error parameters norm

   element = document->NewElement("ErrorParametersNorm");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << error_parameters_norm;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Error gradient norm 

   element = document->NewElement("ErrorGradientNorm");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << error_gradient_norm;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Minimum parameters increment norm

   element = document->NewElement("MinimumParametersIncrementNorm");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << minimum_parameters_increment_norm;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Minimum performance increase 

   element = document->NewElement("MinimumPerformanceIncrease");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << minimum_performance_increase;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Performance goal 

   element = document->NewElement("PerformanceGoal");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << performance_goal;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Gradient norm goal 

   element = document->NewElement("GradientNormGoal");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << gradient_norm_goal;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Maximum generalization performance decreases

   element = document->NewElement("MaximumGeneralizationPerformanceDecreases");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << maximum_generalization_performance_decreases;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Maximum iterations number 

   element = document->NewElement("MaximumIterationsNumber");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << maximum_iterations_number;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Maximum time 

   element = document->NewElement("MaximumTime");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << maximum_time;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve parameters history 

   element = document->NewElement("ReserveParametersHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_parameters_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve parameters norm history 

   element = document->NewElement("ReserveParametersNormHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_parameters_norm_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve performance history

   element = document->NewElement("ReservePerformanceHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_performance_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve generalization performance history

   element = document->NewElement("ReserveGeneralizationPerformanceHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_generalization_performance_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve gradient history 

   element = document->NewElement("ReserveGradientHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_gradient_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve gradient norm history 

   element = document->NewElement("ReserveGradientNormHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_gradient_norm_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve Hessian approximation history

   element = document->NewElement("ReserveHessianApproximationHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_Hessian_approximation_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve elapsed time history 

   element = document->NewElement("ReserveElapsedTimeHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_elapsed_time_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve generalization performance history

   element = document->NewElement("ReserveGeneralizationPerformanceHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_generalization_performance_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Display period

   element = document->NewElement("DisplayPeriod");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << display_period;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Display

   element = document->NewElement("Display");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << display;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   return(document);
}


// void from_XML(const tinyxml2::XMLDocument&) method

/// Loads a Levenberg-Marquardt method object from a XML document.
/// Please mind about the format, wich is specified in the OpenNN manual. 
/// @param document TinyXML document containint the object data.

void LevenbergMarquardtAlgorithm::from_XML(const tinyxml2::XMLDocument& document)
{
    const tinyxml2::XMLElement* root_element = document.FirstChildElement("LevenbergMarquardtAlgorithm");

    if(!root_element)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: LevenbergMarquardtAlgorithm class.\n"
               << "void from_XML(const tinyxml2::XMLDocument&) method.\n"
               << "Levenberg-Marquardt algorithm element is NULL.\n";

        throw std::logic_error(buffer.str());
    }


    // Damping parameter

    const tinyxml2::XMLElement* damping_parameter_element = root_element->FirstChildElement("DampingParameter");

    if(damping_parameter_element)
    {
       const double new_damping_parameter = atof(damping_parameter_element->GetText());

       try
       {
          set_damping_parameter(new_damping_parameter);
       }
       catch(const std::logic_error& e)
       {
          std::cout << e.what() << std::endl;
       }
    }

    // Minimum damping parameter

    const tinyxml2::XMLElement* minimum_damping_parameter_element = root_element->FirstChildElement("MinimumDampingParameter");

    if(minimum_damping_parameter_element)
    {
       const double new_minimum_damping_parameter = atof(minimum_damping_parameter_element->GetText());

       try
       {
          set_minimum_damping_parameter(new_minimum_damping_parameter);
       }
       catch(const std::logic_error& e)
       {
          std::cout << e.what() << std::endl;
       }
    }

    // Maximum damping parameter

    const tinyxml2::XMLElement* maximum_damping_parameter_element = root_element->FirstChildElement("MaximumDampingParameter");

    if(maximum_damping_parameter_element)
    {
       const double new_maximum_damping_parameter = atof(maximum_damping_parameter_element->GetText());

       try
       {
          set_maximum_damping_parameter(new_maximum_damping_parameter);
       }
       catch(const std::logic_error& e)
       {
          std::cout << e.what() << std::endl;
       }
    }

    // Damping parameter factor

    const tinyxml2::XMLElement* damping_parameter_factor_element = root_element->FirstChildElement("DampingParameterFactor");

    if(damping_parameter_factor_element)
    {
       const double new_damping_parameter_factor = atof(damping_parameter_factor_element->GetText());

       try
       {
          set_damping_parameter_factor(new_damping_parameter_factor);
       }
       catch(const std::logic_error& e)
       {
          std::cout << e.what() << std::endl;
       }
    }

   // Warning parameters norm

   const tinyxml2::XMLElement* warning_parameters_norm_element = root_element->FirstChildElement("WarningParametersNorm");

   if(warning_parameters_norm_element)
   {
      const double new_warning_parameters_norm = atof(warning_parameters_norm_element->GetText());

      try
      {
         set_warning_parameters_norm(new_warning_parameters_norm);
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Warning gradient norm 

   const tinyxml2::XMLElement* warning_gradient_norm_element = root_element->FirstChildElement("WarningGradientNorm");

   if(warning_gradient_norm_element)
   {
      const double new_warning_gradient_norm = atof(warning_gradient_norm_element->GetText());

      try
      {
         set_warning_gradient_norm(new_warning_gradient_norm);
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Error parameters norm

   const tinyxml2::XMLElement* error_parameters_norm_element = root_element->FirstChildElement("ErrorParametersNorm");

   if(error_parameters_norm_element)
   {
      const double new_error_parameters_norm = atof(error_parameters_norm_element->GetText());

      try
      {
          set_error_parameters_norm(new_error_parameters_norm);
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Error gradient norm 

   const tinyxml2::XMLElement* error_gradient_norm_element = root_element->FirstChildElement("ErrorGradientNorm");

   if(error_gradient_norm_element)
   {
      const double new_error_gradient_norm = atof(error_gradient_norm_element->GetText());

      try
      {
         set_error_gradient_norm(new_error_gradient_norm);
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Minimum parameters increment norm

   const tinyxml2::XMLElement* minimum_parameters_increment_norm_element = root_element->FirstChildElement("MinimumParametersIncrementNorm");

   if(minimum_parameters_increment_norm_element)
   {
      const double new_minimum_parameters_increment_norm = atof(minimum_parameters_increment_norm_element->GetText());

      try
      {
         set_minimum_parameters_increment_norm(new_minimum_parameters_increment_norm);
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Minimum performance increase 

   const tinyxml2::XMLElement* minimum_performance_increase_element = root_element->FirstChildElement("MinimumPerformanceIncrease");

   if(minimum_performance_increase_element)
   {
      const double new_minimum_performance_increase = atof(minimum_performance_increase_element->GetText());

      try
      {
         set_minimum_performance_increase(new_minimum_performance_increase);
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Performance goal 

   const tinyxml2::XMLElement* performance_goal_element = root_element->FirstChildElement("PerformanceGoal");

   if(performance_goal_element)
   {
      const double new_performance_goal = atof(performance_goal_element->GetText());

      try
      {
         set_performance_goal(new_performance_goal);
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Gradient norm goal 

   const tinyxml2::XMLElement* gradient_norm_goal_element = root_element->FirstChildElement("GradientNormGoal");

   if(gradient_norm_goal_element)
   {
      const double new_gradient_norm_goal = atof(gradient_norm_goal_element->GetText());

      try
      {
         set_gradient_norm_goal(new_gradient_norm_goal);
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Maximum generalization performance decreases

   const tinyxml2::XMLElement* maximum_generalization_performance_decreases_element = root_element->FirstChildElement("MaximumGeneralizationPerformanceDecreases");

   if(maximum_generalization_performance_decreases_element)
   {
      const unsigned new_maximum_generalization_performance_decreases = atoi(maximum_generalization_performance_decreases_element->GetText());

      try
      {
         set_maximum_generalization_performance_decreases(new_maximum_generalization_performance_decreases);
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Maximum iterations number 

   const tinyxml2::XMLElement* maximum_iterations_number_element = root_element->FirstChildElement("MaximumIterationsNumber");

   if(maximum_iterations_number_element)
   {
      const unsigned new_maximum_iterations_number = atoi(maximum_iterations_number_element->GetText());

      try
      {
         set_maximum_iterations_number(new_maximum_iterations_number);
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Maximum time 

   const tinyxml2::XMLElement* maximum_time_element = root_element->FirstChildElement("MaximumTime");

   if(maximum_time_element)
   {
      const double new_maximum_time = atof(maximum_time_element->GetText());

      try
      {
         set_maximum_time(new_maximum_time);
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Reserve parameters history 

   const tinyxml2::XMLElement* reserve_parameters_history_element = root_element->FirstChildElement("ReserveParametersHistory");

   if(reserve_parameters_history_element)
   {
      std::string new_reserve_parameters_history = reserve_parameters_history_element->GetText(); 

      try
      {
         set_reserve_parameters_history(new_reserve_parameters_history != "0");
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Reserve parameters norm history 

   const tinyxml2::XMLElement* reserve_parameters_norm_history_element = root_element->FirstChildElement("ReserveParametersNormHistory");

   if(reserve_parameters_norm_history_element)
   {
      const std::string new_reserve_parameters_norm_history = reserve_parameters_norm_history_element->GetText();

      try
      {
         set_reserve_parameters_norm_history(new_reserve_parameters_norm_history != "0");
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Reserve performance history

   const tinyxml2::XMLElement* reserve_performance_history_element = root_element->FirstChildElement("ReservePerformanceHistory");

   if(reserve_performance_history_element)
   {
      const std::string new_reserve_performance_history = reserve_performance_history_element->GetText();

      try
      {
         set_reserve_performance_history(new_reserve_performance_history != "0");
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Reserve generalization performance history

   const tinyxml2::XMLElement* reserve_generalization_performance_history_element = root_element->FirstChildElement("ReserveGeneralizationPerformanceHistory");

   if(reserve_generalization_performance_history_element)
   {
      const std::string new_reserve_generalization_performance_history = reserve_generalization_performance_history_element->GetText();

      try
      {
         set_reserve_generalization_performance_history(new_reserve_generalization_performance_history != "0");
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;
      }
   }

   // Reserve gradient history 

   const tinyxml2::XMLElement* reserve_gradient_history_element = root_element->FirstChildElement("ReserveGradientHistory");

   if(reserve_gradient_history_element)
   {
      std::string new_reserve_gradient_history = reserve_gradient_history_element->GetText(); 

      try
      {
         set_reserve_gradient_history(new_reserve_gradient_history != "0");
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Reserve gradient norm history 

   const tinyxml2::XMLElement* reserve_gradient_norm_history_element = root_element->FirstChildElement("ReserveGradientNormHistory");

   if(reserve_gradient_norm_history_element)
   {
      const std::string new_reserve_gradient_norm_history = reserve_gradient_norm_history_element->GetText();

      try
      {
         set_reserve_gradient_norm_history(new_reserve_gradient_norm_history != "0");
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Reserve elapsed time history 

   const tinyxml2::XMLElement* reserve_elapsed_time_history_element = root_element->FirstChildElement("ReserveElapsedTimeHistory");

   if(reserve_elapsed_time_history_element)
   {
      const std::string new_reserve_elapsed_time_history = reserve_elapsed_time_history_element->GetText();

      try
      {
         set_reserve_elapsed_time_history(new_reserve_elapsed_time_history != "0");
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Display period

   const tinyxml2::XMLElement* display_period_element = root_element->FirstChildElement("DisplayPeriod");

   if(display_period_element)
   {
      const unsigned new_display_period = atoi(display_period_element->GetText());

      try
      {
         set_display_period(new_display_period);
      }
      catch(const std::logic_error& e)
      {
         std::cout << e.what() << std::endl;		 
      }
   }

   // Display

   const tinyxml2::XMLElement* display_element = root_element->FirstChildElement("Display");

   if(display_element)
   {
      const std::string new_display = display_element->GetText();

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
