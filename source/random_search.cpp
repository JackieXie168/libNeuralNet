/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   R A N D O M   S E A R C H   C L A S S                                                                      */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// OpenNN includes

#include "random_search.h"

namespace OpenNN
{

// DEFAULT CONSTRUCTOR

/// Default constructor. 
/// It creates a random search training algorithm not associated to any performance functional object. 
/// It also initializes the class members to their default values.

RandomSearch::RandomSearch(void) 
 : TrainingAlgorithm()
{
   set_default();
}


// PERFORMANCE FUNCTIONAL CONSTRUCTOR 

/// Performance functional constructor. 
/// It creates a random search training algorithm associated to a performance functional object. 
/// It also initializes the class members to their default values.
/// @param new_performance_functional_pointer Pointer to a performance functional object.

RandomSearch::RandomSearch(PerformanceFunctional* new_performance_functional_pointer)
: TrainingAlgorithm(new_performance_functional_pointer)
{   
   set_default();
}


// XML CONSTRUCTOR 

/// XML constructor. 
/// It creates a random search training algorithm not associated to any performance functional object. 
/// It also loads the rest of class members from a XML document.
/// @param document TinyXML document containing the members of a random search object. 

RandomSearch::RandomSearch(const tinyxml2::XMLDocument& document) : TrainingAlgorithm(document)
{
   from_XML(document);
}


// DESTRUCTOR

/// Destructor.
/// It does not delete any object. 

RandomSearch::~RandomSearch(void)
{

}


// const double& get_warning_parameters_norm(void) const method

/// Returns the minimum value for the norm of the parameters vector at wich a warning message is written to the screen. 

const double& RandomSearch::get_warning_parameters_norm(void) const
{
   return(warning_parameters_norm);       
}


// const double& get_warning_training_rate(void) const method

/// Returns the training rate value at wich a warning message is written to the screen during line minimization.

const double& RandomSearch::get_warning_training_rate(void) const
{
   return(warning_training_rate);
}


// const double& get_error_parameters_norm(void) const method

/// Returns the value for the norm of the parameters vector at wich an error message is 
/// written to the screen and the program exits. 

const double& RandomSearch::get_error_parameters_norm(void) const
{
   return(error_parameters_norm);
}


// const double& get_error_training_rate(void) const method

/// Returns the training rate value at wich the line minimization algorithm is assumed to fail when 
/// bracketing a minimum.

const double& RandomSearch::get_error_training_rate(void) const
{
   return(error_training_rate);
}


// const double& get_performance_goal(void) const method

/// Returns the goal value for the performance. 
/// This is used as a stopping criterion when training a multilayer perceptron

const double& RandomSearch::get_performance_goal(void) const
{
   return(performance_goal);
}


// const unsigned& get_maximum_generalization_performance_decreases(void) const method

/// Returns the maximum number of generalization failures during the training process. 

const unsigned& RandomSearch::get_maximum_generalization_performance_decreases(void) const
{
   return(maximum_generalization_performance_decreases);
}


// const unsigned& get_maximum_iterations_number(void) const method

/// Returns the maximum number of iterations for training.

const unsigned& RandomSearch::get_maximum_iterations_number(void) const
{
   return(maximum_iterations_number);
}


// const double& get_maximum_time(void) const method

/// Returns the maximum training time.  

const double& RandomSearch::get_maximum_time(void) const
{
   return(maximum_time);
}


// const bool& get_reserve_parameters_history(void) const method

/// Returns true if the parameters history matrix is to be reserved, and false otherwise.

const bool& RandomSearch::get_reserve_parameters_history(void) const
{
   return(reserve_parameters_history);     
}


// const bool& get_reserve_parameters_norm_history(void) const method 

/// Returns true if the parameters norm history vector is to be reserved, and false otherwise.

const bool& RandomSearch::get_reserve_parameters_norm_history(void) const
{
   return(reserve_parameters_norm_history);     
}


// const bool& get_reserve_performance_history(void) const method

/// Returns true if the performance history vector is to be reserved, and false otherwise.

const bool& RandomSearch::get_reserve_performance_history(void) const
{
   return(reserve_performance_history);     
}


// const bool& get_reserve_training_direction_history(void) const method

/// Returns true if the training direction history matrix is to be reserved, and false otherwise.

const bool& RandomSearch::get_reserve_training_direction_history(void) const
{
   return(reserve_training_direction_history);     
}


// const bool& get_reserve_training_rate_history(void) const method

/// Returns true if the training rate history vector is to be reserved, and false otherwise.

const bool& RandomSearch::get_reserve_training_rate_history(void) const
{
   return(reserve_training_rate_history);     
}


// const bool& get_reserve_elapsed_time_history(void) const method

/// Returns true if the elapsed time history vector is to be reserved, and false otherwise.

const bool& RandomSearch::get_reserve_elapsed_time_history(void) const
{
   return(reserve_elapsed_time_history);     
}


// const bool& get_reserve_generalization_performance_history(void) const method

/// Returns true if the Generalization performance history vector is to be reserved, and false otherwise.

const bool& RandomSearch::get_reserve_generalization_performance_history(void) const
{
   return(reserve_generalization_performance_history);
}


// const unsigned& get_display_period(void) const method

/// Returns the number of iterations between the training showing progress. 

const unsigned& RandomSearch::get_display_period(void) const
{
   return(display_period);
}


// const double& get_training_rate_reduction_factor(void) const method

/// Returns the reducing factor for the training rate. 

const double& RandomSearch::get_training_rate_reduction_factor(void) const
{
   return(training_rate_reduction_factor);
}


// const unsigned& get_training_rate_reduction_period(void) const method

/// Returns the reducing period for the training rate. 

const unsigned& RandomSearch::get_training_rate_reduction_period(void) const
{
   return(training_rate_reduction_period);
}


// void set_default(void) method

/// Sets all the random search object members to their default values:
/// <ul>
/// <li> Training rate reduction factor: 0.9
/// <li> Training rate reduction period: 10
/// <li> Warning parameters norm: 1.0e6
/// <li> Error parameters norm: 1.0e9
/// <li> Performance goal: -1.0e99
/// <li> Maximum time: 1.0e6
/// <li> Maximum iterations number: 100
/// <li> Reserve potential parameters history: False
/// <li> Reserve potential parameters norm history: False
/// <li> Reserve performance history: False.
/// <li> Display: True
/// <li> Display period: 10
/// </ul>

void RandomSearch::set_default(void)
{   
   // TRAINING PARAMETERS

   first_training_rate = 0.01;

   training_rate_reduction_factor = 0.9;
   training_rate_reduction_period = 10;

   // STOPPING CRITERIA

   performance_goal = -1.0e99;

   maximum_iterations_number = 100;
   maximum_time = 1000.0;

   // TRAINING HISTORY

   reserve_parameters_history = false;
   reserve_parameters_norm_history = false;

   reserve_performance_history = true;

   reserve_training_direction_history = false;
   reserve_training_rate_history = false;
   reserve_elapsed_time_history = false;

   // UTILITIES

   warning_parameters_norm = 1.0e6;
   warning_training_rate = 1.0e6;

   error_parameters_norm = 1.0e9;
   error_training_rate = 1.0e9;

   display = true;
   display_period = 10;
}


// void set_first_training_rate(const double&)

/// Sets the initial training rate in the random search.
/// The training rate is the step given in some training direction.
/// @param new_first_training_rate Firs training rate value.

void RandomSearch::set_first_training_rate(const double& new_first_training_rate)
{
    first_training_rate = new_first_training_rate;
}


// void set_training_rate_reduction_factor(const double&) method

/// Sets a new value for the reduction factor of the training rate. 
/// @param new_training_rate_reduction_factor Reduction factor value.

void RandomSearch::set_training_rate_reduction_factor(const double& new_training_rate_reduction_factor)
{
   training_rate_reduction_factor = new_training_rate_reduction_factor;
}


// void set_training_rate_reduction_period(unsigned) method

/// Sets a new period value for the reduction of the training rate. This is measured in training iterations. 
/// @param new_training_rate_reduction_period Reduction period for the training rate.

void RandomSearch::set_training_rate_reduction_period(const unsigned& new_training_rate_reduction_period)
{
   training_rate_reduction_period = new_training_rate_reduction_period;
}


// void set_reserve_parameters_history(bool) method

/// Makes the potential parameters history vector of vectors to be reseved or not in memory.
/// @param new_reserve_parameters_history True if the potential parameters history is to be reserved, false otherwise.

void RandomSearch::set_reserve_parameters_history(const bool& new_reserve_parameters_history)
{
   reserve_parameters_history = new_reserve_parameters_history;
}


// void set_reserve_parameters_norm_history(bool) method

/// Makes the potential parameters norm history vector to be reseved or not in memory.
/// @param new_reserve_parameters_norm_history True if the potential parameters norm history is to be reserved, 
/// false otherwise.

void RandomSearch::set_reserve_parameters_norm_history(const bool& new_reserve_parameters_norm_history)
{
   reserve_parameters_norm_history = new_reserve_parameters_norm_history;   
}


// void set_reserve_performance_history(bool) method

/// Makes the potential performance history vector to be reseved or not in memory.
/// @param new_reserve_performance_history True if the potential performance history is to be reserved, 
/// false otherwise.

void RandomSearch::set_reserve_performance_history(const bool& new_reserve_performance_history)
{
   reserve_performance_history = new_reserve_performance_history;
}


// void set_reserve_all_training_history(bool) method

/// Makes the training history of all variables to reseved or not in memory.
/// @param new_reserve_all_training_history True if the training history of all variables is to be reserved, 
/// false otherwise.

void RandomSearch::set_reserve_all_training_history(const bool& new_reserve_all_training_history)
{
   // Neural network

   reserve_parameters_history = new_reserve_all_training_history;
   reserve_parameters_norm_history = new_reserve_all_training_history;
   
   // Performance functional

   reserve_performance_history = new_reserve_all_training_history;
  
   // Training algorithm

   reserve_elapsed_time_history = new_reserve_all_training_history;
}


// void set_warning_parameters_norm(const double&) method

/// Sets a new value for the parameters vector norm at which a warning message is written to the 
/// screen. 
/// @param new_warning_parameters_norm Warning norm of parameters vector value. 

void RandomSearch::set_warning_parameters_norm(const double& new_warning_parameters_norm)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_warning_parameters_norm < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: RandomSearch class.\n"
             << "void set_warning_parameters_norm(const double&) method.\n"
             << "Warning parameters norm must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set warning parameters norm

   warning_parameters_norm = new_warning_parameters_norm;     
}



// void set_warning_training_rate(const double&) method

/// Sets a new training rate value at wich a warning message is written to the screen during line 
/// minimization.
/// @param new_warning_training_rate Warning training rate value.

void RandomSearch::set_warning_training_rate(const double& new_warning_training_rate)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_warning_training_rate < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: RandomSearch class.\n" 
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

void RandomSearch::set_error_parameters_norm(const double& new_error_parameters_norm)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_error_parameters_norm < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: RandomSearch class.\n"
             << "void set_error_parameters_norm(const double&) method.\n"
             << "Error parameters norm must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set error parameters norm

   error_parameters_norm = new_error_parameters_norm;
}


// void set_error_training_rate(const double&) method

/// Sets a new training rate value at wich a the line minimization algorithm is assumed to fail when 
/// bracketing a minimum.
/// @param new_error_training_rate Error training rate value.

void RandomSearch::set_error_training_rate(const double& new_error_training_rate)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_error_training_rate < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: RandomSearch class.\n"
             << "void set_error_training_rate(const double&) method.\n"
             << "Error training rate must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set error training rate

   error_training_rate = new_error_training_rate;
}


// void set_performance_goal(const doubleT) method

/// Sets a new goal value for the performance. 
/// This is used as a stopping criterion when training a multilayer perceptron
/// @param new_performance_goal Goal value for the performance.

void RandomSearch::set_performance_goal(const double& new_performance_goal)
{
   performance_goal = new_performance_goal;
}


// void set_maximum_generalization_performance_decreases(const unsigned&) method

/// Sets a new maximum number of generalization failures. 
/// @param new_maximum_generalization_performance_decreases Maximum number of iterations in which the generalization evalutation decreases.

void RandomSearch::set_maximum_generalization_performance_decreases(const unsigned& new_maximum_generalization_performance_decreases)
{
   // Set maximum generalization performace decrases

   maximum_generalization_performance_decreases = new_maximum_generalization_performance_decreases;
}


// void set_maximum_iterations_number(const unsigned&) method

/// Sets a maximum number of iterations for training.
/// @param new_maximum_iterations_number Maximum number of iterations for training.

void RandomSearch::set_maximum_iterations_number(const unsigned& new_maximum_iterations_number)
{
   maximum_iterations_number = new_maximum_iterations_number;
}


// void set_maximum_time(const double&) method

/// Sets a new maximum training time.  
/// @param new_maximum_time Maximum training time.

void RandomSearch::set_maximum_time(const double& new_maximum_time)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_maximum_time < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: RandomSearch class.\n"
             << "void set_maximum_time(const double&) method.\n"
             << "Maximum time must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }
   
   #endif

   // Set maximum time

   maximum_time = new_maximum_time;
}


// void set_reserve_training_direction_history(const bool&) method

/// Makes the training direction history vector of vectors to be reseved or not in memory.
/// @param new_reserve_training_direction_history True if the training direction history matrix is to be reserved, 
/// false otherwise.

void RandomSearch::set_reserve_training_direction_history(const bool& new_reserve_training_direction_history)
{
   reserve_training_direction_history = new_reserve_training_direction_history;          
}


// void set_reserve_training_direction_norm_history(const bool&) method

/// Makes the training direction norm history vector to be reseved or not in memory.
/// @param new_reserve_training_direction_norm_history True if the history of the norm of the training direction is to be reserved,
/// false otherwise.

void RandomSearch::set_reserve_training_direction_norm_history(const bool& new_reserve_training_direction_norm_history)
{
   reserve_training_direction_norm_history = new_reserve_training_direction_norm_history;
}


// void set_reserve_training_rate_history(bool) method

/// Makes the training rate history vector to be reseved or not in memory.
/// @param new_reserve_training_rate_history True if the training rate history vector is to be reserved, false 
/// otherwise.

void RandomSearch::set_reserve_training_rate_history(const bool& new_reserve_training_rate_history)
{
   reserve_training_rate_history = new_reserve_training_rate_history;          
}


// void set_reserve_elapsed_time_history(bool) method

/// Makes the elapsed time over the iterations to be reseved or not in memory. This is a vector.
/// @param new_reserve_elapsed_time_history True if the elapsed time history vector is to be reserved, false 
/// otherwise.

void RandomSearch::set_reserve_elapsed_time_history(const bool& new_reserve_elapsed_time_history)
{
   reserve_elapsed_time_history = new_reserve_elapsed_time_history;     
}


// void set_reserve_generalization_performance_history(bool) method

/// Makes the Generalization performance history to be reserved or not in memory. 
/// This is a vector. 
/// @param new_reserve_generalization_performance_history True if the Generalization performance history is to be reserved, false otherwise. 

void RandomSearch::set_reserve_generalization_performance_history(const bool& new_reserve_generalization_performance_history)  
{
   reserve_generalization_performance_history = new_reserve_generalization_performance_history;
}


// void set_display_period(unsigned) method

/// Sets a new number of iterations between the training showing progress. 
/// @param new_display_period
/// Number of iterations between the training showing progress. 

void RandomSearch::set_display_period(const unsigned& new_display_period)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 
     
   if(new_display_period <= 0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: RandomSearch class.\n"
             << "void set_display_period(const double&) method.\n"
             << "First training rate must be greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   display_period = new_display_period;
}



// Vector<double> calculate_training_direction(void) const method

/// Calculates a random vector to be used as training direction.

Vector<double> RandomSearch::calculate_training_direction(void) const
{   
   const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   Vector<double> random(parameters_number);
   double random_norm;

   do
   { 
      random.randomize_uniform();   
      random_norm = random.calculate_norm();             
   }while(random_norm == 0.0);

   return(random/random_norm);
}


// void resize_training_history(const unsigned&) method

/// Resizes all the training history variables. 
/// @param new_size Size of training history variables. 

void RandomSearch::RandomSearchResults::resize_training_history(const unsigned& new_size)
{

    if(random_search_pointer->get_reserve_parameters_history())
    {
        parameters_history.resize(new_size);
    }

    if(random_search_pointer->get_reserve_parameters_norm_history())
    {
        parameters_norm_history.resize(new_size);
    }

    if(random_search_pointer->get_reserve_performance_history())
    {
        performance_history.resize(new_size);
    }

    if(random_search_pointer->get_reserve_generalization_performance_history())
    {
        generalization_performance_history.resize(new_size);
    }

    if(random_search_pointer->get_reserve_training_direction_history())
    {
        training_direction_history.resize(new_size);
    }

    if(random_search_pointer->get_reserve_training_rate_history())
    {
        training_rate_history.resize(new_size);
    }

    if(random_search_pointer->get_reserve_elapsed_time_history())
    {
        elapsed_time_history.resize(new_size);
    }
}


// std::string to_string(void) const method

/// Returns a string representation of the current random search results structure. 

std::string RandomSearch::RandomSearchResults::to_string(void) const
{
   std::ostringstream buffer;

   // Parameters history

   if(!parameters_history.empty())
   {
     buffer << "% Parameters history:\n"
            << parameters_history << "\n";
   }

   // Parameters norm history

   if(!parameters_norm_history.empty())
   {
       buffer << "% Parameters norm history:\n"
              << parameters_norm_history << "\n"; 
   }
   
   // performance history   

   if(!performance_history.empty())
   {
       buffer << "% performance history:\n"
              << performance_history << "\n"; 
   }

   // Generalization performance history

   if(!generalization_performance_history.empty())
   {
       buffer << "% Generalization performance history:\n"
              << generalization_performance_history << "\n"; 
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

Matrix<std::string> RandomSearch::RandomSearchResults::write_final_results(const unsigned& precision) const
{
   std::ostringstream buffer;

   Vector<std::string> names;
   Vector<std::string> values;

   // Final parameters norm

   names.push_back("Final parameters norm");

   buffer.str("");
   buffer << std::setprecision(precision) <<final_parameters_norm;

   values.push_back(buffer.str());

   // Final performance

   names.push_back("Final performance");

   buffer.str("");
   buffer << std::setprecision(precision) << final_performance;

   values.push_back(buffer.str());

   // Final generalization performance

   const PerformanceFunctional* performance_functional_pointer = random_search_pointer->get_performance_functional_pointer();

   if(performance_functional_pointer->has_generalization())
   {
       names.push_back("Final generalization performance");

       buffer.str("");
       buffer << std::setprecision(precision) << final_generalization_performance;

       values.push_back(buffer.str());
    }

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


// RandomSearchResults* perform_training(void) method

/// Trains a neural network with an associated performance functional according to the random search training algorithm.
/// Training occurs according to the training parameters. 

RandomSearch::RandomSearchResults* RandomSearch::perform_training(void)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   check();

   #endif

   RandomSearchResults* results_pointer = new RandomSearchResults(this);
   results_pointer->resize_training_history(1+maximum_iterations_number);

   // Start training 

   if(display)
   {
      std::cout << "Training with random search...\n";
   }
   

   // Elapsed time

   time_t beginning_time, current_time;
   time(&beginning_time);
   double elapsed_time;

   // Neural network stuff

   NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   Vector<double> parameters = neural_network_pointer->arrange_parameters();
   double parameters_norm;

   // Performance functional stuff
    
   double performance = 0.0;
   double potential_performance = 1.0e99;

   double generalization_performance = 0.0;
   double old_generalization_performance = 0.0;

   unsigned generalization_failures = 0;

   // Training algorithm stuff 

   Vector<double> training_direction(parameters_number);
   double training_rate = 1.0;

   Vector<double> potential_parameters(parameters);
   double potential_parameters_norm;

   Vector<double> parameters_increment(parameters_number);
//   double parameters_increment_norm;

   bool stop_training = false;

   // Main loop 

   for(unsigned iteration = 0; iteration <= maximum_iterations_number; iteration++)
   {             
       // Neural network stuff

       parameters_norm = parameters.calculate_norm();

       if(display && parameters_norm >= warning_parameters_norm)
       {
          std::cout << "OpenNN Warning: Parameters norm is " << parameters_norm << ".\n";
       }

      // Performance functional stuff

       if(iteration == 0)
       {
           performance = performance_functional_pointer->calculate_performance();
           generalization_performance = performance_functional_pointer->calculate_generalization_performance();
       }


      if(iteration != 0 && generalization_performance > old_generalization_performance)
      {
         generalization_failures++;
      }

      potential_performance = performance_functional_pointer->calculate_performance(potential_parameters);

      // Training algorithm stuff

      training_direction = calculate_training_direction();
  
      if(iteration != 0 && iteration%training_rate_reduction_period == 0)
      {
         training_rate *= training_rate_reduction_factor; 
      }       

      parameters_increment = training_direction*training_rate;
//      parameters_increment_norm = parameters_increment.calculate_norm();

      potential_parameters = parameters + parameters_increment;
      potential_parameters_norm = potential_parameters.calculate_norm();

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

      // Training history training algorithm

      if(reserve_training_direction_history)
      {
         results_pointer->training_direction_history[iteration] = training_direction;
      }

      if(reserve_training_rate_history)
      {
         results_pointer->training_rate_history[iteration] = training_rate;
      }

//      if(reserve_potential_parameters_history)
//      {
//         results_pointer->potential_parameters_history[iteration] = potential_parameters;
//      }

//      if(reserve_potential_parameters_norm_history)
//      {
//         results_pointer->potential_parameters_norm_history[iteration] = potential_parameters_norm;
//      }


      if(reserve_elapsed_time_history)
      {
         results_pointer->elapsed_time_history[iteration] = elapsed_time;
      }

      // Stopping Criteria

      if(performance <= performance_goal)
      {
         if(display)
         {
            std::cout << "Iteration " << iteration << ": Performance goal reached.\n";
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
          if(display)
          {
             std::cout << "Parameters norm: " << parameters_norm << "\n"
                       << "Potential parameters norm: " << potential_parameters_norm << "\n"
                       << "Performance: " << performance << "\n"
                       << performance_functional_pointer->write_information()
                       << "Potential performance: " << potential_performance << "\n"
                       << "Training rate: " << training_rate << "\n"
                       << "Elapsed time: " << elapsed_time << std::endl;

             if(generalization_performance != 0)
             {
                std::cout << "Generalization performance: " << generalization_performance << std::endl;
             }
          }

         results_pointer->final_parameters = parameters;
         results_pointer->final_parameters_norm = parameters_norm;

         results_pointer->final_performance = performance;
         results_pointer->final_generalization_performance = generalization_performance;
  
         results_pointer->final_training_direction = training_direction;
         results_pointer->final_training_rate = training_rate;
         results_pointer->elapsed_time = elapsed_time;

         results_pointer->iterations_number = iteration;

         break;
      }

      else if(display && iteration % display_period == 0)
      {
         std::cout << "Iteration " << iteration << ";\n"
                   << "Parameters norm: " << parameters_norm << "\n"
                   << "Potential parameters norm: " << potential_parameters_norm << "\n"
                   << "Performance: " << performance << "\n"
                   << performance_functional_pointer->write_information()
                   << "Potential performance: " << potential_performance << "\n"
                   << "Training rate: " << training_rate << "\n"
                   << "Elapsed time: " << elapsed_time << std::endl; 

         if(generalization_performance != 0)
         {
            std::cout << "Generalization performance: " << generalization_performance << std::endl;
         }
      }

      // Set new parameters

      if(potential_performance < performance)
      {
         parameters = potential_parameters;

         neural_network_pointer->set_parameters(parameters);

         performance = potential_performance;

         generalization_performance = performance_functional_pointer->calculate_generalization_performance();
         old_generalization_performance = generalization_performance;
      }
   }

   return(results_pointer);
}


// std::string write_training_algorithm_type(void) const method

std::string RandomSearch::write_training_algorithm_type(void) const
{
   return("RANDOM_SEARCH");
}


// Matrix<std::string> to_string_matrix(void) const method

// the most representative

Matrix<std::string> RandomSearch::to_string_matrix(void) const
{
    std::ostringstream buffer;

    Vector<std::string> labels;
    Vector<std::string> values;

   // Performance goal

   labels.push_back("Performance goal");

   buffer.str("");
   buffer << performance_goal;

   values.push_back(buffer.str());

   // Maximum generalization failures

   labels.push_back("Maximum generalization performance decreases");

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

/// Prints to the screen the training parameters, the stopping criteria
/// and other user stuff concerning the random search object.

tinyxml2::XMLDocument* RandomSearch::to_XML(void) const 
{
   std::ostringstream buffer;

   tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument;

   // Training algorithm

   tinyxml2::XMLElement* root_element = document->NewElement("RandomSearch");

   document->InsertFirstChild(root_element);

   tinyxml2::XMLElement* element = NULL;
   tinyxml2::XMLText* text = NULL;

   // Training rate reduction factor
   {
   element = document->NewElement("TrainingRateReductionFactor");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << training_rate_reduction_factor;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // Training rate reduction period
   {
   element = document->NewElement("TrainingRateReductionPeriod");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << training_rate_reduction_period;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
   }

   // First training rate
   {
   element = document->NewElement("FirstTrainingRate");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << first_training_rate;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
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

   // Error training rate
   {
   element = document->NewElement("ErrorTrainingRate");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << error_training_rate;

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
   element = document->NewElement("ReserveGeneralizationperformanceHistory");
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


// void from_XML(const tinyxml2::XMLDocument&) method

/// @todo

void RandomSearch::from_XML(const tinyxml2::XMLDocument& document)
{
    const tinyxml2::XMLElement* root_element = document.FirstChildElement("RandomSearch");

    if(!root_element)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: RandomSearch class.\n"
               << "void from_XML(const tinyxml2::XMLDocument&) method.\n"
               << "Random search element is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    // First training rate
    {
        const tinyxml2::XMLElement* element = root_element->FirstChildElement("FirstTrainingRate");

        if(element)
        {
           const double new_first_training_rate = atof(element->GetText());

           try
           {
              set_first_training_rate(new_first_training_rate);
           }
           catch(const std::logic_error& e)
           {
              std::cout << e.what() << std::endl;
           }
        }
    }

    // Training rate reduction factor
    {
        const tinyxml2::XMLElement* element = root_element->FirstChildElement("TrainingRateReductionFactor");

        if(element)
        {
           const double new_training_rate_reduction_factor = atof(element->GetText());

           try
           {
              set_training_rate_reduction_factor(new_training_rate_reduction_factor);
           }
           catch(const std::logic_error& e)
           {
              std::cout << e.what() << std::endl;
           }
        }
    }

    // Training rate reduction period
    {
        const tinyxml2::XMLElement* element = root_element->FirstChildElement("TrainingRateReductionPeriod");

        if(element)
        {
           const unsigned new_training_rate_reduction_period = atoi(element->GetText());

           try
           {
              set_training_rate_reduction_period(new_training_rate_reduction_period);
           }
           catch(const std::logic_error& e)
           {
              std::cout << e.what() << std::endl;
           }
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

    // Reserve training direction norm history
    {
        const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveTrainingDirectionNormHistory");

        if(element)
        {
           const std::string new_reserve_training_direction_norm_history = element->GetText();

           try
           {
              set_reserve_training_direction_norm_history(new_reserve_training_direction_norm_history != "0");
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

   // Display
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
