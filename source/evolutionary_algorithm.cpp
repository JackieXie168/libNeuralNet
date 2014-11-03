/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   E V O L U T I O N A R Y   A L G O R I T H M   C L A S S                                                    */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// OpenNN includes

#include "evolutionary_algorithm.h"

namespace OpenNN
{

// DEFAULT CONSTRUCTOR

/// Default constructor. 
/// It creates a evolutionary training algorithm not associated to any performance functional.
/// It also initializes the class members to their default values.

EvolutionaryAlgorithm::EvolutionaryAlgorithm(void) : TrainingAlgorithm()
{
   set_default();
}


// PERFORMANCE FUNCTIONAL CONSTRUCTOR 

/// Performance functional constructor. 
/// It creates a evolutionary training algorithm associated to a performance functional.
/// It also initializes the class members to their default values.
/// @param new_performance_functional_pointer Pointer to a performance functional object.

EvolutionaryAlgorithm::EvolutionaryAlgorithm(PerformanceFunctional* new_performance_functional_pointer)
: TrainingAlgorithm(new_performance_functional_pointer)
{
   set_default();
}


// XML CONSTRUCTOR

/// XML constructor. 
/// It creates a evolutionary training algorithm not associated to any performance functional.
/// It also loads the class members from a XML document.
/// @param evolutionary_algorithm_document TinyXML document with the evolutionary algorithm object members.

EvolutionaryAlgorithm::EvolutionaryAlgorithm(const tinyxml2::XMLDocument& evolutionary_algorithm_document)
 : TrainingAlgorithm(evolutionary_algorithm_document)
{
}


// DESTRUCTOR

/// Destructor.

EvolutionaryAlgorithm::~EvolutionaryAlgorithm(void)
{

}


// METHODS

// const FitnessAssignmentMethod& get_fitness_assignment_method(void) const method

/// Returns the fitness assignment method used for training.
 
const EvolutionaryAlgorithm::FitnessAssignmentMethod& EvolutionaryAlgorithm::get_fitness_assignment_method(void) const
{
   return(fitness_assignment_method);
}


// std::string write_fitness_assignment_method(void) const method

/// Returns a string with the name of the method used for fitness assignment.  

std::string EvolutionaryAlgorithm::write_fitness_assignment_method(void) const
{
   switch(fitness_assignment_method)
   {
      case LinearRanking:
      {
         return("LinearRanking");
	  }
      break;

	  default:
      {
         std::ostringstream buffer;

         buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
                << "std::string write_fitness_assignment_method(void) const method.\n"
                << "Unknown fitness assignment method.\n";
 
         throw std::logic_error(buffer.str());	     
	  }
      break;
   }
}


// const SelectionMethod& get_selection_method(void) const method

/// Returns the selection method used for training.

const EvolutionaryAlgorithm::SelectionMethod& EvolutionaryAlgorithm::get_selection_method(void) const
{
   return(selection_method);
}


// std::string write_selection_method(void) const method

/// Returns a string with the name of the method used for selection.  

std::string EvolutionaryAlgorithm::write_selection_method(void) const
{
   switch(selection_method)
   {
      case RouletteWheel:
      {
         return("RouletteWheel");
	  }
      break;

	  default:
      {
         std::ostringstream buffer;

         buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
                << "std::string write_selection_method(void) const method.\n"
                << "Unknown selection method.\n";
 
         throw std::logic_error(buffer.str());	     
	  }
      break;
   }
}


// const RecombinationMethod& get_recombination_method(void) const method

/// Returns the recombination method used for training.

const EvolutionaryAlgorithm::RecombinationMethod& EvolutionaryAlgorithm::get_recombination_method(void) const
{
   return(recombination_method);
}


// std::string write_recombination_method(void) const method

/// Returns a string with the name of the method used for recombination.  

std::string EvolutionaryAlgorithm::write_recombination_method(void) const
{
   switch(recombination_method)
   {
      case Line:
      {
         return("Line");
	  }
      break;

      case Intermediate:
      {
         return("Intermediate");
	  }
      break;

	  default:
      {
         std::ostringstream buffer;

         buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
                << "std::string write_recombination_method(void) const method.\n"
                << "Unknown recombination method.\n";
 
         throw std::logic_error(buffer.str());	     
	  }
      break;
   }
}


// const MutationMethod get_mutation_method(void) const method

/// Returns the mutation method used for training.

const EvolutionaryAlgorithm::MutationMethod& EvolutionaryAlgorithm::get_mutation_method(void) const
{
   return(mutation_method);
}


// std::string write_mutation_method(void) const method

/// Returns a string with the name of the method used for mutation.  

std::string EvolutionaryAlgorithm::write_mutation_method(void) const
{
   switch(mutation_method)
   {
      case Normal:
      {
         return("Normal");
	  }
      break;

      case Uniform:
      {
         return("Uniform");
	  }
      break;

	  default:
      {
         std::ostringstream buffer;
 
         buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
                << "std::string get_mutation_method_name(void) const method.\n"
                << "Unknown mutation method.\n";
 
         throw std::logic_error(buffer.str());	     
	  }
      break;
   }
}


// unsigned get_population_size(void) const method

/// Returns the number of individuals in the population.

unsigned EvolutionaryAlgorithm::get_population_size(void) const
{
   return(population.get_rows_number());
}


// const Matrix<double>& get_population(void) const method

/// Returns the population matrix.

const Matrix<double>& EvolutionaryAlgorithm::get_population(void) const
{
   return(population);
}


// const Vector<double>& get_performance(void) const method

/// Returns the actual performance value of all individuals in the population.

const Vector<double>& EvolutionaryAlgorithm::get_performance(void) const
{
   return(performance);
}


// const Vector<double>& get_fitness(void) const method

/// Returns the actual fitness value of all individuals in the population.

const Vector<double>& EvolutionaryAlgorithm::get_fitness(void) const
{
   return(fitness);
}


// const Vector<bool>& get_selection(void) const method

/// Returns the actual selection value of all individuals in the population.

const Vector<bool>& EvolutionaryAlgorithm::get_selection(void) const
{
   return(selection);
}


// const double& get_warning_parameters_norm(void) const method

/// Returns the minimum value for the norm of the parameters vector at wich a warning message is 
/// written to the screen. 

const double& EvolutionaryAlgorithm::get_warning_parameters_norm(void) const
{
   return(warning_parameters_norm);       
}


// const double& get_error_parameters_norm(void) const method

/// Returns the value for the norm of the parameters vector at wich an error message is 
/// written to the screen and the program exits. 

const double& EvolutionaryAlgorithm::get_error_parameters_norm(void) const
{
   return(error_parameters_norm);
}


// const double& get_best_performance_goal(void) const method

/// Returns the goal value for the performance. 
/// This is used as a stopping criterion when training a multilayer perceptron

const double& EvolutionaryAlgorithm::get_best_performance_goal(void) const
{
   return(best_performance_goal);
}


// const unsigned& get_maximum_generalization_performance_decreases(void) const method

/// Returns the maximum number of generalization failures during the training process. 

const unsigned& EvolutionaryAlgorithm::get_maximum_generalization_performance_decreases(void) const
{
   return(maximum_generalization_performance_decreases);
}


// const double& get_maximum_time(void) const method

/// Returns the maximum training time.  

const double& EvolutionaryAlgorithm::get_maximum_time(void) const
{
   return(maximum_time);
}


// const bool& get_reserve_elapsed_time_history(void) const method

/// Returns true if the elapsed time history vector is to be reserved, and false otherwise.

const bool& EvolutionaryAlgorithm::get_reserve_elapsed_time_history(void) const
{
   return(reserve_elapsed_time_history);     
}


// const bool& get_reserve_generalization_performance_history(void) const method

/// Returns true if the Generalization performance history vector is to be reserved, and false otherwise.

const bool& EvolutionaryAlgorithm::get_reserve_generalization_performance_history(void) const
{
   return(reserve_generalization_performance_history);
}


// const unsigned& get_display_period(void) const method

/// Returns the number of iterations between the training showing progress. 

const unsigned& EvolutionaryAlgorithm::get_display_period(void) const
{
   return(display_period);
}



// const bool& get_reserve_population_history(void) const method

/// Returns true if the population history vector of matrices is to be reserved, and false otherwise.

const bool& EvolutionaryAlgorithm::get_reserve_population_history(void) const
{
   return(reserve_population_history);
}


// const bool& get_reserve_best_individual_history(void) const method

/// Returns true if the best individual history vector of vectors is to be reserved, and false otherwise.

const bool& EvolutionaryAlgorithm::get_reserve_best_individual_history(void) const
{
   return(reserve_best_individual_history);
}


// const bool& get_reserve_mean_norm_history(void) const method

/// Returns true if the mean population norm history vector is to be reserved, and false otherwise.

const bool& EvolutionaryAlgorithm::get_reserve_mean_norm_history(void) const
{
   return(reserve_mean_norm_history);
}


// const bool& get_reserve_standard_deviation_norm_history(void) const method

/// Returns true if the standard deviation of the population norm history vector is to be reserved,
/// and false otherwise.

const bool& EvolutionaryAlgorithm::get_reserve_standard_deviation_norm_history(void) const
{
   return(reserve_standard_deviation_norm_history);
}


// const bool& get_reserve_best_norm_history(void) const method

/// Returns true if the norm of the best individual in the population history vector is to be 
/// reserved, and false otherwise.

const bool& EvolutionaryAlgorithm::get_reserve_best_norm_history(void) const
{
   return(reserve_best_norm_history);
}


// const bool& get_reserve_mean_performance_history(void) const method

/// Returns true if the mean performance history vector is to be reserved, and false otherwise.

const bool& EvolutionaryAlgorithm::get_reserve_mean_performance_history(void) const
{
   return(reserve_mean_performance_history);
}


// const bool& get_reserve_standard_deviation_performance_history(void) const method

/// Returns true if the standard deviation of the performance history vector is to be reserved,
/// and false otherwise.

const bool& EvolutionaryAlgorithm::get_reserve_standard_deviation_performance_history(void) const
{
   return(reserve_standard_deviation_performance_history);
}


// const bool& get_reserve_best_performance_history(void) const method

/// Returns true if the best performance history vector is to be reserved, and false otherwise.

const bool& EvolutionaryAlgorithm::get_reserve_best_performance_history(void) const
{
   return(reserve_best_performance_history);
}


// void set(void) method

/// Sets the performance functional pointer of this object to NULL. 
/// It also sets the rest of members to their default values. 

void EvolutionaryAlgorithm::set(void)
{
   performance_functional_pointer = NULL;

   set_default();
}


// void set(PerformanceFunctional*) method

/// Sets a new performance functional pointer to the evolutionary algorithm object. 
/// It also sets the rest of members to their default values. 

void EvolutionaryAlgorithm::set(PerformanceFunctional* new_performance_functional_pointer)
{
   performance_functional_pointer = new_performance_functional_pointer;

   set_default();
}


// void set_default(void) method

/// Sets the members of the evolutionary algorithm object to their default values.
/// Training operators:
/// <ul>
/// <li> Fitness assignment method: Linear ranking.
/// <li> Selection method: Roulette wheel.
/// <li> Recombination method: Intermediate.
/// <li> Mutation method: Normal.
/// </ul>
/// Training parameters:
/// <ul>
/// <li> Population size: 10*parameters_number or 0.
/// <li> Perform elitism: false.
/// <li> Selective pressure: 1.5.
/// <li> Recombination size: 0.25.
/// <li> Mutation rate: = 1/parameters_number or 0.
/// <li> Mutation range: = 0.1
/// </ul>
/// Stopping criteria:
/// <ul> 
/// <li> Performance goal: -1.0e99.
/// <li> Mean performance goal: -1.0e99.
/// <li> Standard deviation of performance goal: -1.0e99.
/// <li> Maximum training time: 1.0e6.
/// <li> Maximum number of generations: 100. 
/// </ul> 
/// Training history:
/// <ul> 
/// <li> Population = false.
/// <li> Mean norm = false.
/// <li> Standard deviation norm = false.
/// <li> Best norm = false.
/// <li> Mean performance = false.
/// <li> Standard deviation performance = false.
/// <li> Best performance = false.
/// </ul> 
/// User stuff: 
/// <ul>
/// <li> Display: true. 
/// <li> Display period: 1. 
/// </ul>

void EvolutionaryAlgorithm::set_default(void)
{
   // Fitness assignment method

   fitness_assignment_method = LinearRanking;

   // Selection method

   selection_method = RouletteWheel;

   // Recombination method

   recombination_method = Intermediate;

   // Mutation method

   mutation_method = Normal;

   // Training parameters

   elitism_size = 2;

   selective_pressure = 1.5;

   recombination_size = 0.25;

   mutation_rate = 0.1;

   mutation_range = 0.1;

   // Stopping criteria

   mean_performance_goal = -1.0e99;
   standard_deviation_performance_goal = 0.0;
   best_performance_goal = -1.0e99;

   maximum_time = 1.0e6;

   maximum_generations_number = 1000;

   // Training history

   reserve_population_history = false;

   reserve_best_individual_history = false;

   reserve_mean_norm_history = false;
   reserve_standard_deviation_norm_history = false;
   reserve_best_norm_history = false;

   reserve_mean_performance_history = false;
   reserve_standard_deviation_performance_history = false;
   reserve_best_performance_history = false;

   reserve_elapsed_time_history = false;

   // User stuff

   display_period = 10;

}


// void set_population_size(unsigned) method

/// Sets a new population with a new number of individuals.  
/// The new population size must be an even number equal or greater than four. 
///
/// @param new_population_size Number of individuals in the population. This must be an even number equal or 
/// greater than four. 

void EvolutionaryAlgorithm::set_population_size(const unsigned& new_population_size)
{
    if(new_population_size == 0)
    {
        population.set();

        performance.set();

        fitness.set();

        selection.set();
    }
    else
    {
       // Control sentence (if debug)

       #ifndef NDEBUG

       check();

       #endif

       const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

       // Control sentence (if debug)

       #ifndef NDEBUG

       if(!neural_network_pointer)
       {
          std::ostringstream buffer;

          buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
                 << "void set_population_size(unsigned) method.\n"
                 << "Neural network pointer is NULL.\n";

          throw std::logic_error(buffer.str());
       }

       #endif

       const unsigned parameters_number = neural_network_pointer->count_parameters_number();

       if(new_population_size < 4)
       {
          std::ostringstream buffer;

          buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
                 << "void set_population_size(unsigned) method.\n"
                 << "New population size must be equal or greater than 4.\n";

          throw std::logic_error(buffer.str());
       }
       else if(new_population_size%2 != 0)
       {
          std::ostringstream buffer;

          buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
                 << "void set_population_size(unsigned) method.\n"
                 << "New population size is not divisible by 2.\n";

          throw std::logic_error(buffer.str());
       }
       else
       {
          // Set population matrix

          population.resize(new_population_size, parameters_number);

          randomize_population_normal();

          // Set performance vector

          performance.resize(new_population_size);

          // Set fitness vector

          fitness.resize(new_population_size);

          // Set selection vector

          selection.resize(new_population_size);
       }
    }
}


// void set_fitness_assignment_method(const std::string&) method

/// Sets a new method for fitness assignment from a string containing the name.
/// Possible values are:
/// <ul>
/// <li> "LinearRanking"
/// </ul>
/// @param new_fitness_assignment_method_name String with name of method for fitness assignment.   

void EvolutionaryAlgorithm::set_fitness_assignment_method(const std::string& new_fitness_assignment_method_name)
{
   if(new_fitness_assignment_method_name == "LinearRanking")
   {
      fitness_assignment_method = LinearRanking;
   }
   else
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void set_fitness_assignment_method(const std::string&) method.\n"
			 << "Unknown fitness assignment method: " << new_fitness_assignment_method_name << ".\n";
   
      throw std::logic_error(buffer.str());	  
   }
}


// void set_selection_method(const std::string&) method

/// Sets a new method for selection from a string containing the name.
/// Possible values are:
/// <ul>
/// <li> "LinearRanking"
/// </ul>
/// @param new_selection_method_name String with name of method for selection.   

void EvolutionaryAlgorithm::set_selection_method(const std::string& new_selection_method_name)
{
   if(new_selection_method_name == "RouletteWheel")
   {
      selection_method = RouletteWheel;
   }
   else
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void set_selection_method(const std::string&) method.\n"
			 << "Unknown selection method: " << new_selection_method_name << ".\n";
   
      throw std::logic_error(buffer.str());	  
   }
}


// void set_recombination_method(const std::string&) method

/// Sets a new method for recombination from a string containing the name.
/// Possible values are:
/// <ul>
/// <li> "Line"
/// <li> "Intermediate"
/// </ul>
/// @param new_recombination_method_name String with name of method for recombination.   

void EvolutionaryAlgorithm::set_recombination_method(const std::string& new_recombination_method_name)
{
   if(new_recombination_method_name == "Line")
   {
      recombination_method = Line;
   }
   else if(new_recombination_method_name == "Intermediate")
   {
      recombination_method = Intermediate;
   }
   else
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void set_recombination_method(const std::string&) method.\n"
			 << "Unknown recombination method: " << new_recombination_method_name << ".\n";
   
      throw std::logic_error(buffer.str());	  
   }
}


// void set_mutation_method(const std::string&) method

/// Sets a new method for mutation from a string containing the name.
/// Possible values are:
/// <ul>
/// <li> "Normal"
/// <li> "Uniform"
/// </ul>
/// @param new_mutation_method_name String with name of method for mutation.   

void EvolutionaryAlgorithm::set_mutation_method(const std::string& new_mutation_method_name)
{
   if(new_mutation_method_name == "Normal")
   {
      mutation_method = Normal;
   }
   else if(new_mutation_method_name == "Uniform")
   {
      mutation_method = Uniform;
   }
   else
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void set_mutation_method(const std::string&) method.\n"
			 << "Unknown mutationg method: " << new_mutation_method_name << ".\n";
   
      throw std::logic_error(buffer.str());	  
   }
}


// void set_population(const Matrix<double>&) method

/// Sets a new population.
///
/// @param new_population Population Matrix.

void EvolutionaryAlgorithm::set_population(const Matrix<double>& new_population)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

    const unsigned population_size = get_population_size();

    if(population_size == 0 && new_population.empty())
    {
        return;
    }

    check();

    const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();   

   if(new_population.get_rows_number() != population_size)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void set_population(const Matrix<double>&) method.\n"
             << "New population size is not equal to population size.\n";

      throw std::logic_error(buffer.str());	  
   }
   else if(new_population.get_columns_number() != parameters_number)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void set_population(const Matrix<double>&) method.\n"
             << "New number of parameters is not equal to number of parameters.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set population

   population = new_population;
}


// void set_performance(const Vector<double>&) method

/// Sets a new population performance vector.
///
/// @param new_performance Population performance values.

void EvolutionaryAlgorithm::set_performance(const Vector<double>& new_performance)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   const unsigned population_size = get_population_size();

   if(new_performance.size() != population_size)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void set_performance(const Vector<double>&) method.\n"
             << "Size is not equal to population size.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set performance

   performance = new_performance;
}


// void set_fitness(const Vector<double>&) method

/// Sets a new population fitness vector.
///
/// @param new_fitness Population fitness values.

void EvolutionaryAlgorithm::set_fitness(const Vector<double>& new_fitness)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   const unsigned population_size = get_population_size();

   if(new_fitness.size() != population_size)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void set_fitness(Vector<double>) method.\n"
             << "Size is not equal to population size.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set fitness

   fitness = new_fitness;
}


// void set_selection(const Vector<bool>&) method

/// Sets a new population selection vector.
///
/// @param new_selection Population selection values.

void EvolutionaryAlgorithm::set_selection(const Vector<bool>& new_selection)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   const unsigned population_size = get_population_size();

   if(new_selection.size() != population_size)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void set_selection(Vector<double>) method.\n"
             << "Size is not equal to population size.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set selection

   selection = new_selection;
}


// void set_reserve_population_history(bool) method

/// Makes the population history vector of matrices to be reseved or not in memory.
/// @param new_reserve_population_history True if the population history vector of matrices is to be reserved, false 
/// otherwise.

void EvolutionaryAlgorithm::set_reserve_population_history(const bool& new_reserve_population_history)
{
   reserve_population_history = new_reserve_population_history;
}


// void set_reserve_best_individual_history(bool) method

/// Makes the best individual history vector of vectors to be reseved or not in memory.
/// @param new_reserve_best_individual_history True if the best individual history vector of vectors is to be reserved, 
/// false otherwise.

void EvolutionaryAlgorithm::set_reserve_best_individual_history(const bool& new_reserve_best_individual_history)
{
   reserve_best_individual_history = new_reserve_best_individual_history;
}


// void set_reserve_mean_norm_history(bool) method

/// Makes the mean norm history vector to be reseved or not in memory.
///
/// @param new_reserve_mean_norm_history True if the mean norm history vector is to be reserved, false otherwise.

void EvolutionaryAlgorithm::set_reserve_mean_norm_history(const bool& new_reserve_mean_norm_history)
{
   reserve_mean_norm_history = new_reserve_mean_norm_history;
}


// void set_reserve_standard_deviation_norm_history(bool) method

/// Makes the standard deviation norm history vector to be reseved or not in memory.
///
/// @param new_reserve_standard_deviation_norm_history True if the standard deviation norm history vector is to be 
/// reserved, false otherwise.

void EvolutionaryAlgorithm::
set_reserve_standard_deviation_norm_history(const bool& new_reserve_standard_deviation_norm_history)
{
   reserve_standard_deviation_norm_history = new_reserve_standard_deviation_norm_history;
}


// void set_reserve_best_norm_history(bool) method

/// Makes the best norm history vector to be reseved or not in memory.
///
/// @param new_reserve_best_norm_history True if the best norm history vector is to be reserved, false otherwise.

void EvolutionaryAlgorithm::set_reserve_best_norm_history(const bool& new_reserve_best_norm_history)
{
   reserve_best_norm_history = new_reserve_best_norm_history;
}


// void set_reserve_mean_performance_history(bool) method

/// Makes the mean performance history vector to be reseved or not in memory.
///
/// @param new_reserve_mean_performance_history True if the mean performance history vector is to be reserved, false 
/// otherwise.

void EvolutionaryAlgorithm::set_reserve_mean_performance_history(const bool& new_reserve_mean_performance_history) 
{
   reserve_mean_performance_history = new_reserve_mean_performance_history;
}


// void set_reserve_standard_deviation_performance_history(bool) method

/// Makes the standard deviation performance history vector to be reseved or not in memory.
///
/// @param new_reserve_standard_deviation_performance_history True if the standard deviation performance history vector 
/// is to be reserved, false otherwise.

void EvolutionaryAlgorithm
::set_reserve_standard_deviation_performance_history(const bool& new_reserve_standard_deviation_performance_history)
{
   reserve_standard_deviation_performance_history = new_reserve_standard_deviation_performance_history;
}


// void set_reserve_best_performance_history(bool) method

/// Makes the best performance history vector to be reseved or not in memory.
///
/// @param new_reserve_best_performance_history True if the best performance history vector is to be reserved, 
/// false otherwise.

void EvolutionaryAlgorithm::set_reserve_best_performance_history(const bool& new_reserve_best_performance_history)
{
   reserve_best_performance_history = new_reserve_best_performance_history;
}


// void set_reserve_all_training_history(bool) method

/// Makes the training history of all variables to reseved or not in memory.
///
/// @param new_reserve_all_training_history True if the training history of all variables is to be reserved, 
/// false otherwise.

void EvolutionaryAlgorithm::set_reserve_all_training_history(const bool& new_reserve_all_training_history)
{
   // Multilayer perceptron

   reserve_population_history = new_reserve_all_training_history;

   reserve_best_individual_history = new_reserve_all_training_history;

   reserve_mean_norm_history = new_reserve_all_training_history;
   reserve_standard_deviation_norm_history = new_reserve_all_training_history;
   reserve_best_norm_history = new_reserve_all_training_history;

   // Objective functional

   reserve_mean_performance_history = new_reserve_all_training_history;
   reserve_standard_deviation_performance_history = new_reserve_all_training_history;
   reserve_best_performance_history = new_reserve_all_training_history;

   // Training algorithm 

   reserve_elapsed_time_history = new_reserve_all_training_history;
}


// Vector<double> get_individual(const unsigned&) const method

/// Returns the Vector of parameters corresponding to the individual i in the population.
///
/// @param i Index of individual in the population.

Vector<double> EvolutionaryAlgorithm::get_individual(const unsigned& i) const
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   const unsigned population_size = get_population_size();

   if(i >= population_size)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "Vector<double> get_individual(const unsigned&) const method.\n"
             << "Index must be less than population size.\n";

      throw std::logic_error(buffer.str());	  
   }
  
   #endif

   // Get individual

   const Vector<double> individual = population.arrange_row(i);

   return(individual);
}


// set_individual(const unsigned&, Vector<double>) method

/// Sets a new Vector of parameters to the individual i in the population. 
///
/// @param i Index of individual in the population.
/// @param individual Vector of parameters to be assigned to individual i.

void EvolutionaryAlgorithm::set_individual(const unsigned& i, const Vector<double>& individual)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 
 
   const unsigned size = individual.size();

   const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   const unsigned population_size = get_population_size();

   if(i >= population_size)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "set_individual(const unsigned&, Vector<double>) method.\n"
             << "Index must be less than population size.\n";

      throw std::logic_error(buffer.str());	  
   }
   else if(size != parameters_number)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "set_individual(const unsigned&, Vector<double>) method.\n"
             << "Size must be equal to number of parameters.\n";

      throw std::logic_error(buffer.str());	  
   }
  
   #endif

   // Get individual

   population.set_row(i, individual);
}


// unsigned calculate_best_individual_index(void) const method

/// Returns the index of the individual with greatest fitness.

unsigned EvolutionaryAlgorithm::calculate_best_individual_index(void) const
{
    return(fitness.calculate_maximal_index());
}


// void set_warning_parameters_norm(const double&) method

/// Sets a new value for the parameters vector norm at which a warning message is written to the 
/// screen. 
/// @param new_warning_parameters_norm Warning norm of parameters vector value. 

void EvolutionaryAlgorithm::set_warning_parameters_norm(const double& new_warning_parameters_norm)
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


// void set_error_parameters_norm(const double&) method

/// Sets a new value for the parameters vector norm at which an error message is written to the 
/// screen and the program exits. 
/// @param new_error_parameters_norm Error norm of parameters vector value. 

void EvolutionaryAlgorithm::set_error_parameters_norm(const double& new_error_parameters_norm)
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


// void set_best_performance_goal(const double&) method

/// Sets a new goal value for the performance.
/// This is used as a stopping criterion when training a multilayer perceptron.
/// @param new_best_performance_goal Goal value for the performance.

void EvolutionaryAlgorithm::set_best_performance_goal(const double& new_best_performance_goal)
{
   best_performance_goal = new_best_performance_goal;
}


// void set_maximum_generalization_performance_decreases(const unsigned&) method

/// Sets a new maximum number of generalization failures. 
/// @param new_maximum_generalization_performance_decreases Maximum number of iterations in which the generalization evalutation decreases. 

void EvolutionaryAlgorithm::set_maximum_generalization_performance_decreases(const unsigned& new_maximum_generalization_performance_decreases)
{
   maximum_generalization_performance_decreases = new_maximum_generalization_performance_decreases;
}


// void set_maximum_time(const double&) method

/// Sets a new maximum training time.  
/// @param new_maximum_time Maximum training time.

void EvolutionaryAlgorithm::set_maximum_time(const double& new_maximum_time)
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


// void set_reserve_elapsed_time_history(const bool&) method

/// Makes the elapsed time over the iterations to be reseved or not in memory. This is a vector.
/// @param new_reserve_elapsed_time_history True if the elapsed time history vector is to be reserved, false 
/// otherwise.

void EvolutionaryAlgorithm::set_reserve_elapsed_time_history(const bool& new_reserve_elapsed_time_history)
{
   reserve_elapsed_time_history = new_reserve_elapsed_time_history;     
}


// void set_reserve_generalization_performance_history(const bool&) method

/// Makes the Generalization performance history to be reserved or not in memory. 
/// This is a vector. 
/// @param new_reserve_generalization_performance_history True if the Generalization performance history is to be reserved, false otherwise. 

void EvolutionaryAlgorithm::set_reserve_generalization_performance_history(const bool& new_reserve_generalization_performance_history)  
{
   reserve_generalization_performance_history = new_reserve_generalization_performance_history;
}


// void set_display_period(const unsigned&) method

/// Sets a new number of iterations between the training showing progress. 
/// @param new_display_period
/// Number of iterations between the training showing progress. 

void EvolutionaryAlgorithm::set_display_period(const unsigned& new_display_period)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 
     
   if(new_display_period <= 0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: TrainingAlgorithm class.\n"
             << "void set_display_period(const unsigned&) method.\n"
             << "First training rate must be greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   display_period = new_display_period;
}



// Vector<double> calculate_population_norm(void) const method

/// Returns a vector containing the norm of each individual in the population.

Vector<double> EvolutionaryAlgorithm::calculate_population_norm(void) const
{
   const unsigned population_size = get_population_size();

   Vector<double> population_norm(population_size);

   const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   Vector<double> individual(parameters_number);

   for(unsigned i = 0; i < population_size; i++)
   {
      individual = get_individual(i);
           
      population_norm[i] = individual.calculate_norm();     
   }               
   
   return(population_norm);            
}


// double calculate_mean_performance(void) const method

/// Returns the mean value of the individuals performance. 

double EvolutionaryAlgorithm::calculate_mean_performance(void) const
{
   return(performance.calculate_mean());
}


// double calculate_standard_deviation_performance(void) const method

/// Returns the standard deviation value of the individuals performance. 

double EvolutionaryAlgorithm::calculate_standard_deviation_performance(void) const
{
   return(performance.calculate_standard_deviation());
}


// Training parameters

// const bool& get_elitism_size(void) const method

/// Returns the number of individuals which will always be selected for recombination.

const unsigned& EvolutionaryAlgorithm::get_elitism_size(void) const
{
   return(elitism_size);
}


// const double& get_selective_pressure(void) const method 

/// Returns the selective pressure value.

const double& EvolutionaryAlgorithm::get_selective_pressure(void) const
{
   return(selective_pressure);
}


// const double& get_recombination_size(void) const method

/// Returns the recombination size value.

const double& EvolutionaryAlgorithm::get_recombination_size(void) const
{
   return(recombination_size);
}


// const double& get_mutation_rate(void) const method

/// Returns the mutation rate value.

const double& EvolutionaryAlgorithm::get_mutation_rate(void) const
{
   return(mutation_rate);
}


// const double& get_mutation_range(void) const method

/// Returns the mutation range value.

const double& EvolutionaryAlgorithm::get_mutation_range(void) const
{
   return(mutation_range);
}


// const double& get_mean_performance_goal(void) const method

/// Returns the mean performance value of the population at which training will stop.

const double& EvolutionaryAlgorithm::get_mean_performance_goal(void) const
{
   return(mean_performance_goal);
}


// const double& get_standard_deviation_performance_goal(void) const method

/// Returns the standard deviation of the performance at which training will stop.

const double& EvolutionaryAlgorithm::get_standard_deviation_performance_goal(void) const
{
   return(standard_deviation_performance_goal);
}


// const unsigned& get_maximum_generations_number(void) const method

/// Returns the maximum number of generations to train. 

const unsigned& EvolutionaryAlgorithm::get_maximum_generations_number(void) const
{
   return(maximum_generations_number);
}


// void set_elitism_size(const unsigned&) method

/// Sets a new elitism size to the evolutionary algorithm.
/// The elitism size is the number of individuals which will always be selected for recombination.
/// @param new_elitism_size Elitism size to be set.

void EvolutionaryAlgorithm::set_elitism_size(const unsigned& new_elitism_size)
{
    const unsigned half_population_size = get_population_size()/2;

    if(new_elitism_size > half_population_size)
    {
       std::ostringstream buffer;

       buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
              << "void set_elitism_size(const unsigned&) method.\n"
              << "Eltism size (" << new_elitism_size << ") must be less or equal than half the population size (" << half_population_size << ").\n";

       throw std::logic_error(buffer.str());
    }

   elitism_size = new_elitism_size;
}


// void set_selective_pressure(const double&) method

/// Sets a new value for the selective pressure parameter.
/// Linear ranking allows values for the selective pressure greater than 0.
/// @param new_selective_pressure Selective pressure value.

void EvolutionaryAlgorithm::set_selective_pressure(const double& new_selective_pressure)
{
    if(new_selective_pressure <= 0.0)
    {
       std::ostringstream buffer;

       buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
              << "void set_selective_pressure(const double&) method. "
              << "Selective pressure must be greater than 0.\n";

       throw std::logic_error(buffer.str());
    }

    // Set selective pressure

    selective_pressure = new_selective_pressure;
}


// void set_recombination_size(const double&) method

/// Sets a new value for the recombination size parameter.
/// The recombination size value must be equal or greater than 0.
///
/// @param new_recombination_size Recombination size value. This must be equal or greater than 0.

void EvolutionaryAlgorithm::set_recombination_size(const double& new_recombination_size)
{
   if(new_recombination_size < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void set_recombination_size(const double&) method.\n"
             << "Recombination size must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   // Set recombination size

   recombination_size = new_recombination_size;
}


// void set_mutation_rate(const double&) method

/// Sets a new value for the mutation rate parameter.
/// The mutation rate value must be between 0 and 1.
///
/// @param new_mutation_rate Mutation rate value. This value must lie in the interval [0,1]. 

void EvolutionaryAlgorithm::set_mutation_rate(const double& new_mutation_rate)
{
   // Control sentence

   if(new_mutation_rate < 0.0 || new_mutation_rate > 1.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void set_mutation_rate(const double&) method.\n"
             << "Mutation rate must be a value between 0 and 1.\n";

      throw std::logic_error(buffer.str());	  
   }

   // Set mutation rate

   mutation_rate = new_mutation_rate;
}


// void set_mutation_range(const double&) method

/// Sets a new value for the mutation range parameter.
/// The mutation range value must be 0 or a positive number. 
///
/// @param new_mutation_range Mutation range value. This must be equal or greater than 0.

void EvolutionaryAlgorithm::set_mutation_range(const double& new_mutation_range)
{
   // Control sentence

   if(new_mutation_range < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void set_mutation_range(const double&) method.\n"
             << "Mutation range must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   // Set mutation range

   mutation_range = new_mutation_range;
}


// void set_maximum_generations_number(unsigned) method

/// Sets a new value for the maximum number of generations to perform_training.
/// The maximum number of generations value must be a positive number. 
/// @param new_maximum_generations_number Maximum number of generations value.

void EvolutionaryAlgorithm::set_maximum_generations_number(const unsigned& new_maximum_generations_number)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_maximum_generations_number == 0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void set_maximum_generations_number(unsigned) method.\n"
             << "Maximum number of generations must be greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set maximum number of generations

   maximum_generations_number = new_maximum_generations_number;
}



// void set_mean_performance_goal(const double&) method

/// Sets a new value for the mean performance goal stopping criterion.
/// @param new_mean_performance_goal Goal value for the mean performance of the population. 

void EvolutionaryAlgorithm::set_mean_performance_goal(const double& new_mean_performance_goal)
{
   mean_performance_goal = new_mean_performance_goal;
}


// void set_standard_deviation_performance_goal(const double&) method

/// Sets a new value for the standard deviation performance goal stopping criterion.
/// @param new_standard_deviation_performance_goal Goal for the standard deviation performance of the population. 

void EvolutionaryAlgorithm::set_standard_deviation_performance_goal(const double& new_standard_deviation_performance_goal)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(new_standard_deviation_performance_goal < 0.0)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void set_standard_deviation_performance_goal(const double&) method.\n"
             << "Standard deviation of performance goal must be equal or greater than 0.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set standard deviation of performance goal

   standard_deviation_performance_goal = new_standard_deviation_performance_goal;

}

// void set_fitness_assignment_method(FitnessAssignmentMethod) method

/// Sets a new fitness assignment method to be used for training.
/// @param new_fitness_assignment_method Fitness assignment method chosen for training.

void EvolutionaryAlgorithm::set_fitness_assignment_method
(const EvolutionaryAlgorithm::FitnessAssignmentMethod& new_fitness_assignment_method)
{
   fitness_assignment_method = new_fitness_assignment_method;
}


// void set_selection_method(SelectionMethod) method

/// Sets a new selection method to be used for training.
///
/// @param new_selection_method Selection method chosen for training.

void EvolutionaryAlgorithm::
set_selection_method(const EvolutionaryAlgorithm::SelectionMethod& new_selection_method)
{
   selection_method = new_selection_method;
}


// void set_recombination_method(RecombinationMethod) method

/// Sets a new recombination method to be used for training.
///
/// @param new_recombination_method Recombination method chosen for training. 

void EvolutionaryAlgorithm
::set_recombination_method(const EvolutionaryAlgorithm::RecombinationMethod& new_recombination_method)
{
   recombination_method = new_recombination_method;
}


// void set_mutation_method(MutationMethod) method

/// Sets a new mutation method to be used for training.
///
/// @param new_mutation_method Mutation method chosen for training. 

void EvolutionaryAlgorithm::set_mutation_method(const EvolutionaryAlgorithm::MutationMethod& new_mutation_method)
{
   mutation_method = new_mutation_method;
}	


// void initialize_population(const double&) method

/// Initializes the population matrix with a given value.
/// @param new_value Initialization value. 

void EvolutionaryAlgorithm::initialize_population(const double& new_value)
{
   population.initialize(new_value);
}



// void randomize_population_uniform(void) method

/// Initializes the parameters of all the individuals in the population at random, with values 
/// comprised between -1 and 1.

void EvolutionaryAlgorithm::randomize_population_uniform(void)
{
   population.randomize_uniform();
}


// void randomize_population_uniform(const double&, const double&) method

/// Initializes the parameters of all the individuals in the population at random, with values 
/// comprised between a minimum and a maximum value.
///
/// @param minimum Minimum initialization value.
/// @param maximum Maximum initialization value.

void EvolutionaryAlgorithm::randomize_population_uniform(const double& minimum, const double& maximum)
{
   population.randomize_uniform(minimum, maximum);
}


// void randomize_population_uniform(Vector<double>, Vector<double>) method

/// Initializes the parameters of all the individuals in the population at random, with values 
/// comprised between different minimum and maximum values for each variable.
///
/// @param minimum Vector of minimum initialization values.
/// @param maximum Vector of maximum initialization values.

void EvolutionaryAlgorithm::randomize_population_uniform(const Vector<double>& minimum, const Vector<double>& maximum)
{
   const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();   

   // Control sentence (if debug)

   #ifndef NDEBUG 

   const unsigned minimum_size = minimum.size();
   const unsigned maximum_size = maximum.size();

   if(minimum_size != parameters_number || maximum_size != parameters_number)   
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void randomize_population_uniform(Vector<double>, Vector<double>).\n"
             << "Minimum value and maximum value sizes must be equal to number of parameters.\n";
 
      throw std::logic_error(buffer.str());	  
   }

   #endif

   Vector<double> individual(parameters_number);

   const unsigned population_size = get_population_size();

   for(unsigned i = 0; i < population_size; i++)
   {
      individual.randomize_uniform(minimum, maximum);

      set_individual(i, individual);
   }
}


// void randomize_population_normal(void) method

/// Initializes the parameters of all the individuals in the population with random values chosen
/// from a normal distribution with mean 0 and standard deviation 1.

void EvolutionaryAlgorithm::randomize_population_normal(void)
{
   population.randomize_normal();
}


// void randomize_population_normal(const double&, const double&) method

/// Initializes the parameters of all the individuals in the population with random values chosen
/// from a normal distribution with a given mean and a given standard deviation.
///
/// @param mean Mean of normal distribution.
/// @param standard_deviation Standard deviation of normal distribution.

void EvolutionaryAlgorithm::randomize_population_normal(const double& mean, const double& standard_deviation)
{
   population.randomize_normal(mean, standard_deviation);
}


// void randomize_population_normal(Vector<double>, Vector<double>) method

/// Initializes the parameters of all the individuals in the population with random values chosen
/// from normal distributions with different mean and standard deviation for each free parameter.
///
/// @param mean Vector of mean values.
/// @param standard_deviation Vector of standard deviation values.

void EvolutionaryAlgorithm::
randomize_population_normal(const Vector<double>& mean, const Vector<double>& standard_deviation)
{
   const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();   

   // Control sentence (if debug)

   #ifndef NDEBUG 

   const unsigned mean_size = mean.size();
   const unsigned standard_deviation_size = standard_deviation.size();

   if(mean_size != parameters_number || standard_deviation_size != parameters_number)   
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void randomize_population_normal(Vector<double>, Vector<double>).\n"
             << "Mean and standard deviation sizes must be equal to number of parameters.\n";
 
      throw std::logic_error(buffer.str());	  
   }

   #endif

   Vector<double> individual(parameters_number);

   const unsigned population_size = get_population_size();

   for(unsigned i = 0; i < population_size; i++)
   {
      individual.randomize_normal(mean, standard_deviation);

      set_individual(i, individual);
   }
}


// void perform_fitness_assignment(void) method

/// Assigns a fitness value to all the individuals in the population according to the finess assignment operator.

void EvolutionaryAlgorithm::perform_fitness_assignment(void)
{
   switch(fitness_assignment_method)
   {
      case LinearRanking:
      { 
         perform_linear_ranking_fitness_assignment();
      }

      break;

	  default:
	  {
         std::ostringstream buffer;

         buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
                << "void perform_fitness_assignment(void).\n"
                << "Unknown fitness assignment method.\n";
 
         throw std::logic_error(buffer.str());	     
	  }
	  break;
   }
}


// void perform_selection(void) method

/// Selects for recombination some individuals from the population according to the selection operator.

void EvolutionaryAlgorithm::perform_selection(void)
{
   switch(selection_method)
   {
      case RouletteWheel:
      {
         perform_roulette_wheel_selection();
      }
      break;

	  default:
	  {
         std::ostringstream buffer;

         buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
                << "void perform_selection(void).\n"
                << "Unknown selection method.\n";
 
         throw std::logic_error(buffer.str());	     
	  }
	  break;
   }

   // Control sentence (if debug)

   #ifndef NDEBUG

   const unsigned selected_individuals_number = selection.count_occurrences(true);

   const unsigned population_size = get_population_size();

   if(selected_individuals_number != population_size/2)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void perform_selection(void).\n"
             << "Number of selected individuals is not equal to half of the population size.\n";

      throw std::logic_error(buffer.str());
   }

   #endif
}


// void perform_recombination(void) method

/// Recombinates the selected individuals according to the recombination operator.

void EvolutionaryAlgorithm::perform_recombination(void)
{
   switch(recombination_method)
   {
      case Intermediate:
      {
         perform_intermediate_recombination();
      }
      break;

      case Line:
      {
         perform_line_recombination();
      } 
      break;

	  default:
	  {
         std::ostringstream buffer;
 
         buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
                << "void perform_recombination(void).\n"
                << "Unknown recombination method.\n";
 
         throw std::logic_error(buffer.str());	     
	  }
	  break;
   }
}


// void perform_mutation(void) method

/// Mutates the population matrix according to the mutation operator.

void EvolutionaryAlgorithm::perform_mutation(void)
{
   switch(mutation_method)
   {
      case Normal:
      {
         perform_normal_mutation();
      }
      break;

      case Uniform:
      {
         perform_uniform_mutation();
      }
      break;

	  default:
	  {
         std::ostringstream buffer;

         buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
                << "void perform_mutationg(void).\n"
                << "Unknown mutation method.\n";
 
         throw std::logic_error(buffer.str());	     
	  }
	  break;
   }
}


// void evolve_population(void) method

/// Generates a new population matrix by applying fitness assignment, selection, recombination and mutation.

void EvolutionaryAlgorithm::evolve_population(void)
{
   // Fitness assignment
  
   perform_fitness_assignment();

   // Selection

   perform_selection();

   // Recombination

   perform_recombination();

   // Mutation

   perform_mutation();
}


// void evaluate_population(void) method

/// Evaluates the performance functional of all individuals in the population.
/// Results are stored in the performance vector.

void EvolutionaryAlgorithm::evaluate_population(void)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(performance_functional_pointer == NULL)   
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void evaluate_population(void).\n"
             << "Performance functional pointer is NULL.\n";
 
      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Neural network

   const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(!neural_network_pointer)   
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void evaluate_population(void).\n"
             << "Neural network pointer is NULL.\n";
 
      throw std::logic_error(buffer.str());	  
   }

   #endif

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   Vector<double> individual(parameters_number);

   // Evaluate performance functional for all individuals

   const unsigned population_size = get_population_size();

   for(unsigned i = 0; i < population_size; i++)
   {
      individual = get_individual(i);

      performance[i] = performance_functional_pointer->calculate_performance(individual);
      
      if(!(performance[i] > -1.0e99 && performance[i] < 1.0e99))
      {
         std::ostringstream buffer;

         buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
                << "void evaluate_population(void) method.\n"
                << "Performance of individual " << i << " is not a real number.\n";

         throw std::logic_error(buffer.str());	     
      }                
   }
}


// void perform_linear_ranking_fitness_assignment(void) method

/// Ranks all individuals in the population by their performance,
/// so that the least fit individual has rank 1 and the fittest individual has rank [population size].
/// It then assigns them a fitness value linearly proportional to their rank.
/// The smallest fitness corresponds to the smallest performance,
/// and the greatest fitness to the greatest performance.
/// Results are stored in the fitness vector.

void EvolutionaryAlgorithm::perform_linear_ranking_fitness_assignment(void)
{
   // Sorted performance vector

   const Vector<unsigned> rank = performance.calculate_greater_rank();

   // Perform linear ranking fitness assignment
   // Cannot do that without loop because of different types of fitness and rank vectors

   const unsigned population_size = get_population_size();

   for(unsigned i = 0; i < population_size; i++)
   {
      fitness[i] = selective_pressure*rank[i];
   }
}


// void perform_roulette_wheel_selection(void) method

/// This metod performs selection with roulette wheel selection.
/// It selects half of the individuals from the population.
/// Results are stored in the selection vector. 

void EvolutionaryAlgorithm::perform_roulette_wheel_selection(void)
{
   const unsigned population_size = get_population_size();

   // Set selection vector to false 

   selection.initialize(false);

   const Vector<unsigned> elite_individuals = fitness.calculate_maximal_indices(elitism_size);

   for(unsigned i = 0; i < elitism_size; i++)
   {
       const unsigned elite_individual_index = elite_individuals[i];

       selection[elite_individual_index] = true;
   }

   const unsigned selection_target = population_size/2 - elitism_size;

   if(selection_target <= 0)
   {
       return;
   }

   // Cumulative fitness vector

   const Vector<double> cumulative_fitness = fitness.calculate_cumulative();

   const double fitness_sum = fitness.calculate_sum();

   // Select individuals until the desired number of selections is obtained

   unsigned selection_count = 0;

   double pointer;

   while(selection_count != selection_target)
   {
      // Random number between 0 and total cumulative fitness

      pointer = calculate_random_uniform(0, fitness_sum);

      // Perform selection

      if(pointer < cumulative_fitness[0])
      {
         if(!selection[0])
         {
            selection[0] = true;
            selection_count++;
         }
      }
      else
      {
          for(unsigned i = 1; i < population_size; i++)
          {
             if(pointer < cumulative_fitness[i] && pointer >= cumulative_fitness[i-1])
             {
                if(!selection[i])
                {
                   selection[i] = true;
                   selection_count++;
                }
             }
          }
      }
   }

   // Control sentence (if debug)

   #ifndef NDEBUG

   if(selection.count_occurrences(true) != population_size/2)
   {
       std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void perform_roulette_wheel_selection(void) method.\n"
             << "Selection count (" << selection.count_occurrences(true) << ") is not equal to half population size (" << population_size/2 << ").\n";

      throw std::logic_error(buffer.str());
   }

   #endif
}


// void perform_intermediate_recombination(void) method

/// Performs inediate recombination between pairs of selected individuals to generate a new
/// population. 
/// Each selected individual is to be recombined with two other selected individuals chosen at random. 
/// Results are stored in the population matrix.

void EvolutionaryAlgorithm::perform_intermediate_recombination(void)
{
   const unsigned population_size = get_population_size();

    #ifndef NDEBUG

    if(selection.count_occurrences(true) != population_size/2)
    {
        std::ostringstream buffer;

       buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
              << "void perform_intermediate_recombination(void) method.\n"
              << "Selection count (" << selection.count_occurrences(true) << ") is not equal to half population size (" << population_size/2 << ").\n";

       throw std::logic_error(buffer.str());
    }

    #endif

   const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();
     
   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   Matrix<double> new_population(population_size, parameters_number);

   Vector<double> parent_1(parameters_number);
   Vector<double> parent_2(parameters_number);

   Vector<double> offspring(parameters_number);

   Matrix<unsigned> recombination(population_size, 2);

   // Start recombination   

   unsigned new_population_size_count = 0;

   bool parent_2_candidate;

   unsigned parent_2_candidate_index;

   double scaling_factor;

   for(unsigned i = 0; i < population_size; i++)
   {
      if(selection[i])
      {
         // Set parent 1

         parent_1 = get_individual(i);

         // Generate 2 offspring with parent 1

         for(unsigned j = 0; j < 2; j++)
         {
            // Choose parent 2 at random among selected individuals   

            parent_2_candidate = false;

            do{
               // Integer random number beteen 0 and population size

               parent_2_candidate_index = (unsigned)calculate_random_uniform(0.0, population_size);

               // Check if candidate for parent 2 is ok

               if(selection[parent_2_candidate_index] && parent_2_candidate_index != i)
               {
                  parent_2_candidate = true;

                  recombination[new_population_size_count][0] = i;

                  recombination[new_population_size_count][1] = parent_2_candidate_index;

                  parent_2 = get_individual(parent_2_candidate_index);

                  // Perform inediate recombination between parent 1 and parent 2

                  for(unsigned j = 0; j < parameters_number; j++)
                  {
                     // Choose the scaling factor to be a random number between
                     // -recombination_size and 1+recombination_size for each
                     // variable anew.

                     scaling_factor = calculate_random_uniform(-recombination_size, 1.0 + recombination_size);

                     offspring[j] = scaling_factor*parent_1[j] + (1.0 - scaling_factor)*parent_2[j];
                  }

                  // Add offspring to new_population matrix

                  new_population.set_row(new_population_size_count, offspring);   
                  
                  new_population_size_count++;
               }
            }while(parent_2_candidate != true);
         }
      }
   }

   // Count number of new individuals control sentence

   #ifndef NDEBUG

   if(new_population_size_count != population_size)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void perform_intermediate_recombination(void) method.\n"
             << "Count new population size is not equal to population size.\n";

      throw std::logic_error(buffer.str());	  
   }

   #endif

   // Set new population

   population = new_population;
}


// void perform_line_recombination(void) method

/// Performs line recombination between pairs of selected individuals to generate a new population.
/// Each selected individual is to be recombined with two other selected individuals chosen at random. 
/// Results are stored in the population matrix.

void EvolutionaryAlgorithm::perform_line_recombination(void)
{    
   const unsigned population_size = get_population_size();

    #ifndef NDEBUG

    if(selection.count_occurrences(true) != population_size/2)
    {
        std::ostringstream buffer;

       buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
              << "void perform_line_recombination(void) method.\n"
              << "Selection count (" << selection.count_occurrences(true) << ") is not equal to half population size (" << population_size/2 << ").\n";

       throw std::logic_error(buffer.str());
    }

    #endif

   const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();
     
   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   Matrix<double> new_population(population_size, parameters_number);

   Vector<double> parent_1(parameters_number);
   Vector<double> parent_2(parameters_number);

   Vector<double> offspring(parameters_number);
   Vector<double> parent_1_term(parameters_number);
   Vector<double> parent_2_term(parameters_number);

   Matrix<unsigned> recombination(population_size, 2);

   // Start recombination   

   unsigned new_population_size_count = 0;

   bool parent_2_candidate;

   unsigned parent_2_candidate_index;

   double scaling_factor;

   for(unsigned i = 0; i < population_size; i++)
   {
      if(selection[i])
      {
         // Set parent 1

         parent_1 = get_individual(i);

         // Generate 2 offspring with parent 1

         for(unsigned j = 0; j < 2; j++)
         {
            // Choose parent 2 at random among selected individuals   

            parent_2_candidate = false;

            do
            {
               // Integer random number beteen 0 and population size

               parent_2_candidate_index = (unsigned)calculate_random_uniform(0.0, (double)population_size);

               // Check if candidate for parent 2 is ok

               if(selection[parent_2_candidate_index] && parent_2_candidate_index != i)
               {
                  parent_2_candidate = true;

                  recombination[new_population_size_count][0] = i;
                  recombination[new_population_size_count][1] = parent_2_candidate_index;

                  parent_2 = get_individual(parent_2_candidate_index);

                  // Perform inediate recombination between parent 1 and parent 2

                  // Choose the scaling factor to be a random number between
                  // -recombination_size and 1+recombination_size for all
                  // variables.

                  scaling_factor = calculate_random_uniform(-recombination_size , 1.0+recombination_size);

                  parent_1_term = parent_1*scaling_factor;
                  parent_2_term = parent_2*(1.0 - scaling_factor); 

                  offspring = parent_1_term + parent_2_term;

                  // Add offspring to new_population matrix

                  new_population.set_row(new_population_size_count, offspring);   

                  new_population_size_count++;
               }
            }while(!parent_2_candidate);
         }
      }
   }

   // Count new population size control sentence

   if(new_population_size_count != population_size)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
             << "void perform_line_recombination(void) method.\n"
             << "Count new population size is not equal to population size.\n";

      throw std::logic_error(buffer.str());	  
   }

   // Set new population

   population = new_population;
}


// void perform_normal_mutation(void) method

/// Performs normal mutation to all individuals in order to generate a new population.
/// Results are stored in the population matrix.

void EvolutionaryAlgorithm::perform_normal_mutation(void)
{
   const unsigned population_size = get_population_size();

   const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();
     
   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   Vector<double> individual(parameters_number);

   double pointer;

   for(unsigned i = 0; i < population_size; i++)
   {
      individual = get_individual(i);

      for(unsigned j = 0; j < parameters_number; j++)
      {
         // Random number between 0 and 1

         pointer = calculate_random_uniform(0.0, 1.0);

         if(pointer < mutation_rate)
         {
            individual[j] += calculate_random_normal(0.0, mutation_range);
         }
      }

      set_individual(i, individual);
   }
}  


// void perform_uniform_mutation(void) method

/// Performs uniform mutation to all individuals in order to generate a new population.
/// Results are stored in the population matrix.

void EvolutionaryAlgorithm::perform_uniform_mutation(void)
{
   const unsigned population_size = get_population_size();

   const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();
     
   const unsigned parameters_number = neural_network_pointer->count_parameters_number();
   
   Vector<double> individual(parameters_number, 0.0);

   double pointer;

   for(unsigned i = 0; i < population_size; i++)
   {
      individual = get_individual(i);

      for(unsigned j = 0; j < parameters_number; j++)
      {
         // random number between 0 and 1

          pointer = calculate_random_uniform(0.0, 1.0);

         if(pointer < mutation_rate)
         {
            individual[j] += calculate_random_uniform(-mutation_range, mutation_range);
         }
      }

      set_individual(i, individual);
   }
}


// std::string to_string(void) const method

/// Returns a string representation of the current evolutionary algorithm resutls structure. 

std::string EvolutionaryAlgorithm::EvolutionaryAlgorithmResults::to_string(void) const
{
   std::ostringstream buffer;

   // Population history

   if(!population_history.empty())
   {
	   if(!population_history[0].empty())
	   {
          buffer << "% Population history:\n"
                 << population_history << "\n"; 
	   }
   }

   // Best individual history

   if(!best_individual_history.empty())
   {
      if(!population_history[0].empty())
	  {
          buffer << "% Best individual history:\n"
                 << best_individual_history << "\n"; 
	  }
   }

   // Mean norm history   

   if(!mean_norm_history.empty())
   {
       buffer << "% Mean norm history:\n"
              << mean_norm_history << "\n"; 
   }

   // Standard deviation norm history

   if(!standard_deviation_norm_history.empty())
   {
       buffer << "% Standard deviation norm history:\n"
              << standard_deviation_norm_history << "\n"; 
   }

   // Best norm history 

   if(!best_norm_history.empty())
   {
       buffer << "% Best norm history:\n"
              << best_norm_history << "\n"; 
   }

   // performance history

   if(!performance_history.empty())
   {
       buffer << "% performance history:\n"
              << performance_history << "\n"; 
   }

   // Mean performance history

   if(!mean_performance_history.empty())
   {
       buffer << "% Mean performance history:\n"
              << mean_performance_history << "\n"; 
   }

   // Standard deviation performance history

   if(!standard_deviation_performance_history.empty())
   {
       buffer << "% Standard deviation performance history:\n"
              << standard_deviation_performance_history << "\n"; 
   }

   // Best performance history

   if(!best_performance_history.empty())
   {
       buffer << "% Best performance history:\n"
              << best_performance_history << "\n"; 
   }

   // Generalization performance history

   if(!generalization_performance_history.empty())
   {
       buffer << "% Generalization performance history:\n"
              << generalization_performance_history << "\n"; 
   }

   // Elapsed time history   

   if(!elapsed_time_history.empty())
   {
       buffer << "% Elapsed time history:\n"
              << elapsed_time_history << "\n"; 
   }

   return(buffer.str());
}


// void resize_training_history(const unsigned&) method

/// Resizes all the training history variables. 
/// @param new_size Size of training history variables. 

void EvolutionaryAlgorithm::EvolutionaryAlgorithmResults::resize_training_history(const unsigned& new_size) 
{
//    evolutionary_algorithm_pointer->set_reserve_population_history(false);
//    evolutionary_algorithm_pointer->set_reserve_best_individual_history(false);
//    evolutionary_algorithm_pointer->set_reserve_elapsed_time_history(false);

    if(evolutionary_algorithm_pointer->get_reserve_population_history())
    {
         population_history.resize(new_size);
    }

    if(evolutionary_algorithm_pointer->get_reserve_best_individual_history())
    {
        best_individual_history.resize(new_size);
    }

    if(evolutionary_algorithm_pointer->get_reserve_mean_norm_history())
    {
        mean_norm_history.resize(new_size);
    }

    if(evolutionary_algorithm_pointer->get_reserve_standard_deviation_norm_history())
    {
        standard_deviation_norm_history.resize(new_size);
    }

    if(evolutionary_algorithm_pointer->get_reserve_best_norm_history())
    {
        best_norm_history.resize(new_size);
    }

    if(evolutionary_algorithm_pointer->get_reserve_mean_performance_history())
    {
        mean_performance_history.resize(new_size);
    }

    if(evolutionary_algorithm_pointer->get_reserve_standard_deviation_performance_history())
    {
        standard_deviation_performance_history.resize(new_size);
    }
// Bug?
    if(evolutionary_algorithm_pointer->get_reserve_best_performance_history())
    {
        best_performance_history.resize(new_size);
    }
//
    if(evolutionary_algorithm_pointer->get_reserve_generalization_performance_history())
    {
        generalization_performance_history.resize(new_size);
    }

    if(evolutionary_algorithm_pointer->get_reserve_elapsed_time_history())
    {
        elapsed_time_history.resize(new_size);
    }
}


// Matrix<std::string> write_final_results(const unsigned& precision) const method

Matrix<std::string> EvolutionaryAlgorithm::EvolutionaryAlgorithmResults::write_final_results(const unsigned& precision) const
{
   std::ostringstream buffer;

   Vector<std::string> names;
   Vector<std::string> values;

   // Final mean norm of the population.

   names.push_back("Final mean norm");

   buffer.str("");
   buffer << std::setprecision(precision) << final_mean_norm;

   values.push_back(buffer.str());

   // Final standard deviation of the population norm.

   names.push_back("Final standard deviation norm");

   buffer.str("");
   buffer << std::setprecision(precision) << final_standard_deviation_norm;

   values.push_back(buffer.str());

   // Final norm of the best individual ever.

   names.push_back("Final best norm");

   buffer.str("");
   buffer << std::setprecision(precision) << final_best_norm;

   values.push_back(buffer.str());

   // Final mean population performance.

   names.push_back("Final mean performance");

   buffer.str("");
   buffer << std::setprecision(precision) << final_mean_performance;

   values.push_back(buffer.str());

   // Final standard deviation of the population performance.

   names.push_back("Final standard deviation performance");

   buffer.str("");
   buffer << std::setprecision(precision) << final_standard_deviation_performance;

   values.push_back(buffer.str());

   // Performance of the best individual ever

   names.push_back("Final best performance");

   buffer.str("");
   buffer << std::setprecision(precision) << final_best_performance;

   values.push_back(buffer.str());

   // Final generalization performance

   const PerformanceFunctional* performance_functional_pointer = evolutionary_algorithm_pointer->get_performance_functional_pointer();

   if(performance_functional_pointer->has_generalization())
   {
       names.push_back("Final generalization performance");

       buffer.str("");
       buffer << std::setprecision(precision) << final_generalization_performance;

       values.push_back(buffer.str());
    }

   // Generations number

   names.push_back("Generations number");

   buffer.str("");
   buffer << std::setprecision(precision) << generations_number;

   values.push_back(buffer.str());

   // Total elapsed time in the training process.

   names.push_back("Elapsed time");

   buffer.str("");
   buffer << std::setprecision(precision) << elapsed_time;

   values.push_back(buffer.str());

   // Matrix

   const unsigned rows_number = names.size();
   const unsigned columns_number = 2;

   Matrix<std::string> final_results(rows_number, columns_number);

   final_results.set_column(0, names);
   final_results.set_column(1, values);

   return(final_results);
}


// EvolutionaryAlgorithmResults* perform_training(void) method

/// Trains a neural network with an associated performance function according to the evolutionary algorithm.
/// Training occurs according to the training operators and their related parameters.
/// @todo

EvolutionaryAlgorithm::EvolutionaryAlgorithmResults* EvolutionaryAlgorithm::perform_training(void)
{
    #ifndef NDEBUG

    check();

    const unsigned population_size = get_population_size();

    if(population_size == 0)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
               << "EvolutionaryAlgorithmResults* perform_training(void) method.\n"
               << "Population size is zero.\n";

        throw std::logic_error(buffer.str());
    }

    #endif

   if(display)
   {
      std::cout << "Training with the evolutionary algorithm...\n";
   }

   EvolutionaryAlgorithmResults* results_pointer = new EvolutionaryAlgorithmResults(this);

   results_pointer->resize_training_history(1+maximum_generations_number);

   unsigned generalization_failures = 0;

   time_t beginning_time, current_time;
   time(&beginning_time);
   double elapsed_time;

   bool stop_training = false;

   // Performance functional

   Vector<double> population_norm;

   double mean_norm;
   double standard_deviation_norm;

   Vector<double> best_individual;
   unsigned best_individual_index;
   double best_norm = 0.0;

   double best_performance_ever = 1.0e99;

   double best_generation_performance = 1.0e99;

   double generalization_performance = 0.0; 
//   double old_generalization_performance = 0.0;

    // Neural network stuff

   NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

   // Main loop

   for(unsigned generation = 0; generation <= maximum_generations_number; generation++)
   {
      // Population stuff

      if(reserve_population_history)
      {
         results_pointer->population_history[generation] = population;
      }

      population_norm = calculate_population_norm();

      // Mean norm 

      mean_norm = population_norm.calculate_mean();

      if(reserve_mean_norm_history)
      {
         results_pointer->mean_norm_history[generation] = mean_norm;
      }

      // Standard deviation of norm

      standard_deviation_norm = population_norm.calculate_standard_deviation();

      if(reserve_standard_deviation_norm_history)
      {
         results_pointer->standard_deviation_norm_history[generation] = standard_deviation_norm;
      }
    
      // Population evaluation

      evaluate_population();

      best_generation_performance = performance.calculate_minimum();

     if(best_generation_performance < best_performance_ever)
     {
         best_individual_index = performance.calculate_minimal_index();

         best_individual = get_individual(best_individual_index);

        neural_network_pointer->set_parameters(best_individual);

        best_norm = best_individual.calculate_norm();

        best_performance_ever = best_generation_performance;

        //old_generalization_performance = generalization_performance;

        generalization_performance = performance_functional_pointer->calculate_generalization_performance();
     }

      // Best individual 

      if(reserve_best_individual_history)
      {
         results_pointer->best_individual_history[generation] = best_individual;
      }

      // Best individual norm

      if(reserve_best_norm_history)
      {
         results_pointer->best_norm_history[generation] = best_norm;
      }

      // Mean performance

      const double mean_performance = performance.calculate_mean();

      if(reserve_mean_performance_history)
      {
         results_pointer->mean_performance_history[generation] = mean_performance;
      }

      // Standard deviation of performance

      const double standard_deviation_performance = performance.calculate_standard_deviation();

      if(reserve_standard_deviation_performance_history)
      {
         results_pointer->standard_deviation_performance_history[generation] = standard_deviation_performance;
      }

      // Best performance

      if(reserve_best_performance_history)
      {
         results_pointer->best_performance_history[generation] = best_performance_ever;
      }

      // Generalization performance

      if(reserve_generalization_performance_history)
      {
         results_pointer->generalization_performance_history[generation] = generalization_performance;
      }

      // Elapsed time

      time(&current_time);
      elapsed_time = difftime(current_time, beginning_time);

      if(reserve_elapsed_time_history)
      {
         results_pointer->elapsed_time_history[generation] = elapsed_time;
      }

      // Training history neural network

      if(reserve_population_history)
      {
         results_pointer->population_history[generation] = population;
      }

      if(reserve_best_individual_history)
      {
         results_pointer->best_individual_history[generation] = best_individual;
      }

      if(reserve_mean_norm_history)
      {
         results_pointer->mean_norm_history[generation] = mean_norm;
      }

      if(reserve_standard_deviation_norm_history)
      {
         results_pointer->standard_deviation_norm_history[generation] = standard_deviation_norm;
      }

      if(reserve_best_norm_history)
      {
         results_pointer->best_norm_history[generation] = best_norm;
      }

      // Training history training algorithm

      if(reserve_mean_performance_history)
      {
         results_pointer->mean_performance_history[generation] = mean_performance;
      }

      if(reserve_standard_deviation_performance_history)
      {
         results_pointer->standard_deviation_performance_history[generation] = standard_deviation_performance;
      }

      if(reserve_best_performance_history)
      {
         results_pointer->best_performance_history[generation] = best_performance_ever;
      }

      if(reserve_elapsed_time_history)
      {
         results_pointer->elapsed_time_history[generation] = elapsed_time;
      }

      // Stopping criteria

      if(best_performance_ever <= best_performance_goal)
      {
         if(display)
         {
            std::cout << "Generation " << generation << ": Performance goal reached.\n"
                      << performance_functional_pointer->write_information();
         }

		 stop_training = true;
      }

      if(mean_performance <= mean_performance_goal)
      {
         if(display)
         {
            std::cout << "Generation " << generation << ": Mean performance goal reached.\n";
         }
         
		 stop_training = true;
      }

      if(standard_deviation_performance <= standard_deviation_performance_goal)
      {
         if(display)
         {
            std::cout << "Generation " << generation << ": Standard deviation of performance goal reached.\n";
         }
         
		 stop_training = true;
      }

      else if(generalization_failures > maximum_generalization_performance_decreases)
      {
         if(display)
         {
            std::cout << "Generation " << generation << ": Maximum generalization performance decreases reached.\n";
            std::cout << "Generalization performance decreases: "<< generalization_failures << std::endl;
         }

         stop_training = true;
      }

      else if(elapsed_time >= maximum_time)
      {
         if(display)
         {
            std::cout << "Generation " << generation << ": Maximum training time reached.\n";
         }

		 stop_training = true;
      }

      else if(generation == maximum_generations_number)
      {
         if(display)
         {
            std::cout << "Generation " << generation << ": Maximum number of generations reached.\n";
         }

         stop_training = true;
      }

      if(stop_training)
      {
          if(display)
          {
             std::cout << "Mean norm: " << mean_norm << "\n"
                       << "Standard deviation of norm: " << standard_deviation_norm << "\n"
                       << "Best norm: " << best_norm << "\n"
                       << "Mean performance: " << mean_performance << "\n"
                       << "Standard deviation of performance: " << standard_deviation_performance << "\n"
                       << "Best performance: " << best_performance_ever << "\n"
                       << performance_functional_pointer->write_information()
                       << "Elapsed time: " << elapsed_time << ";\n";
          }

          results_pointer->resize_training_history(1+generation);

         results_pointer->final_mean_norm = mean_norm;
         results_pointer->final_standard_deviation_norm = standard_deviation_norm;
         results_pointer->final_best_norm = best_norm;
         results_pointer->final_mean_performance = mean_performance;
         results_pointer->final_standard_deviation_performance = standard_deviation_performance;
         results_pointer->final_best_performance = best_performance_ever;
         results_pointer->final_generalization_performance = generalization_performance;
         results_pointer->elapsed_time = elapsed_time;
         results_pointer->generations_number = generation;

         break;
	  }
      else if(display && generation % display_period == 0)
      {
         std::cout << "Generation " << generation << ";\n"
                   << "Mean norm: " << mean_norm << "\n" 
                   << "Standard deviation of norm: " << standard_deviation_norm << "\n"
                   << "Best norm: " << best_norm << "\n"
                   << "Mean performance: " << mean_performance << "\n"
                   << "Standard deviation of performance: " << standard_deviation_performance << "\n"
                   << "Best performance: " << best_performance_ever << "\n"
                   << performance_functional_pointer->write_information()
                   << "Elapsed time: " << elapsed_time << ";\n";
      }

      // Update stuff

 //     old_generalization_performance = generalization_performance;

      selection.initialize(false);

      evolve_population();

   }

   return(results_pointer);
}


// std::string write_training_algorithm_type(void) const method

std::string EvolutionaryAlgorithm::write_training_algorithm_type(void) const
{
   return("EVOLUTIONARY_ALGORITHM");
}


// Matrix<std::string> to_string_matrix(void) const method

// the most representative

Matrix<std::string> EvolutionaryAlgorithm::to_string_matrix(void) const
{
    std::ostringstream buffer;

    Vector<std::string> labels;
    Vector<std::string> values;

    // Population size

    labels.push_back("Population size");

    buffer.str("");
    buffer << get_population_size();

    values.push_back(buffer.str());

    // Fitness assignment method

    labels.push_back("Fitness assignment method");
    values.push_back(write_fitness_assignment_method());

    // Selection method

    labels.push_back("Selection method");
    values.push_back(write_selection_method());

    // Recombination method

    labels.push_back("Recombination");
    values.push_back(write_recombination_method());

    // Mutation method

    labels.push_back("Mutation method");
    values.push_back(write_mutation_method());

    // Elitism size

    labels.push_back("Elitism size");

    buffer.str("");
    buffer << elitism_size;

    values.push_back(buffer.str());

    // Selective pressure

    labels.push_back("Selective pressure");

    buffer.str("");
    buffer << selective_pressure;

    values.push_back(buffer.str());

    // Recombination size

    labels.push_back("Recombination size");

    buffer.str("");
    buffer << recombination_size;

    values.push_back(buffer.str());

    // Mutation rate

    labels.push_back("Mutation rate");

    buffer.str("");
    buffer << mutation_rate;

    values.push_back(buffer.str());

    // Mutation range

    labels.push_back("Mutation range");

    buffer.str("");
    buffer << mutation_range;

    values.push_back(buffer.str());

   // Best performance goal

   labels.push_back("Best performance goal");

   buffer.str("");
   buffer << best_performance_goal;

   values.push_back(buffer.str());

   // Maximum generalization failures

   labels.push_back("Maximum generalization failures");

   buffer.str("");
   buffer << maximum_generalization_performance_decreases;

   values.push_back(buffer.str());

   // Maximum generations number

   labels.push_back("Maximum generations number");

   buffer.str("");
   buffer << maximum_generations_number;

   values.push_back(buffer.str());

   // Maximum time

   labels.push_back("Maximum time");

   buffer.str("");
   buffer << maximum_time;

   values.push_back(buffer.str());

   // Reserve generalization performance history

   labels.push_back("Reserve generalization performance history");

   buffer.str("");
   buffer << reserve_generalization_performance_history;

   values.push_back(buffer.str());

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

/// Prints to the screen the members of the evolutionary algorithm object.
///
/// Training operators:
/// <ul>
/// <li> Fitness assignment method.
/// <li> Selection method.
/// <li> Recombination method.
/// <li> Mutation method.
/// </ul>
///
/// Training parameters:
/// <ul>
/// <li> Population size.
/// <li> Selective pressure.
/// <li> Recombination size.
/// <li> Mutation rate.
/// <li> Mutation range.
/// </ul>
///
/// Stopping criteria:
/// <ul> 
/// <li> Performance goal.
/// <li> Mean performance goal.
/// <li> Standard deviation of performance goal.
/// <li> Maximum time.
/// <li> Maximum number of generations. 
/// </ul> 
///  
/// User stuff: 
/// <ul>
/// <li> Display. 
/// <li> Display period. 
/// <li> Reserve elapsed time.
/// <li> Reserve mean norm history.
/// <li> Reserve standard deviation of norm history.
/// <li> Reserve best norm history.
/// <li> Reserve mean performance history.
/// <li> Reserve standard deviation of performance history.
/// <li> Reserve best performance history.
/// </ul>
///
/// Population matrix. 

tinyxml2::XMLDocument* EvolutionaryAlgorithm::to_XML(void) const
{
   std::ostringstream buffer;

   tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument;

   // Evolutionary algorithm

   tinyxml2::XMLElement* root_element = document->NewElement("EvolutionaryAlgorithm");

   document->InsertFirstChild(root_element);

   tinyxml2::XMLElement* element = NULL;
   tinyxml2::XMLText* text = NULL;

   // Population

   element = document->NewElement("Population");
   root_element->LinkEndChild(element);

   const std::string population_string = population.to_string();

   text = document->NewText(population_string.c_str());
   element->LinkEndChild(text);

   // Fitness assignment method
   
   element = document->NewElement("FitnessAssignmentMethod");
   root_element->LinkEndChild(element);

   text = document->NewText(write_fitness_assignment_method().c_str());
   element->LinkEndChild(text);

   // Selection method

   element = document->NewElement("SelectionMethod");
   root_element->LinkEndChild(element);

   text = document->NewText(write_selection_method().c_str());
   element->LinkEndChild(text);

   // Recombination method

   element = document->NewElement("RecombinationMethod");
   root_element->LinkEndChild(element);

   text = document->NewText(write_recombination_method().c_str());
   element->LinkEndChild(text);

   // Mutation method

   element = document->NewElement("MutationMethod");
   root_element->LinkEndChild(element);

   text = document->NewText(write_mutation_method().c_str());
   element->LinkEndChild(text);

   // Elitism

   element = document->NewElement("ElitismSize");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << elitism_size;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Selective pressure. 

   element = document->NewElement("SelectivePressure");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << selective_pressure;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Recombination size. 

   element = document->NewElement("RecombinationSize");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << recombination_size;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Mutation rate.

   element = document->NewElement("MutationRate");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << mutation_rate;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Mutation range

   element = document->NewElement("MutationRange");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << mutation_range;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);
    
   // Mean performance goal

   element = document->NewElement("MeanPerformanceGoal");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << mean_performance_goal;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Standard deviation performance goal

   element = document->NewElement("StandardDeviationPerformanceGoal");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << standard_deviation_performance_goal;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Best performance goal

   element = document->NewElement("BestPerformanceGoal");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << best_performance_goal;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Maximum generalization performance decreases

   element = document->NewElement("MaximumGeneralizationPerformanceDecreases");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << maximum_generalization_performance_decreases;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Maximum generations number

   element = document->NewElement("MaximumGenerationsNumber");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << maximum_generations_number;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Maximum time

   element = document->NewElement("MaximumTime");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << maximum_time;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve mean norm history

   element = document->NewElement("ReserveMeanNormHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_mean_norm_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve standard deviation norm history

   element = document->NewElement("ReserveStandardDeviationNormHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_standard_deviation_norm_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve best norm history

   element = document->NewElement("ReserveBestNormHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_best_norm_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve mean performance history

   element = document->NewElement("ReserveMeanPerformanceHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_mean_performance_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve standard deviation performance history

   element = document->NewElement("ReserveStandardDeviationPerformanceHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_standard_deviation_performance_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve best performance history

   element = document->NewElement("ReserveBestPerformanceHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_best_performance_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   // Reserve generalization performance history

   element = document->NewElement("ReserveGeneralizationPerformanceHistory");
   root_element->LinkEndChild(element);

   buffer.str("");
   buffer << reserve_generalization_performance_history;

   text = document->NewText(buffer.str().c_str());
   element->LinkEndChild(text);

   return(document);
}


// void from_XML(const tinyxml2::XMLDocument&) method

/// Loads a evolutionary algorithm object from a XML document.
/// Please mind about the file format, wich is specified in the User's Guide. 
/// @param document TinyXML document with the evolutionary algorithm object members.

void EvolutionaryAlgorithm::from_XML(const tinyxml2::XMLDocument& document)
{
   const tinyxml2::XMLElement* root_element = document.FirstChildElement("EvolutionaryAlgorithm");

   if(!root_element)
   {
       std::ostringstream buffer;

       buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
              << "void from_XML(const tinyxml2::XMLDocument&) method.\n"
              << "Evolutionary algorithm element is NULL.\n";

       throw std::logic_error(buffer.str());
   }

   set_default();

   // Population
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("Population");

       if(element)
       {
          const char* population_text = element->GetText();

          if(population_text)
          {
             Matrix<double> new_population;
             new_population.parse(population_text);

             const unsigned new_population_size = new_population.get_rows_number();

             set_population_size(new_population_size);

             set_population(new_population);
          }
       }
   }


   // Fitness assignment method
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("FitnessAssignmentMethod");

       if(element)
       {
          const std::string new_fitness_assignment_method = element->GetText();

          try
          {
             set_fitness_assignment_method(new_fitness_assignment_method);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Selection method
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("SelectionMethod");

       if(element)
       {
          const std::string new_selection_method = element->GetText();

          try
          {
             set_selection_method(new_selection_method);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Recombination method
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("RecombinationMethod");

       if(element)
       {
          const std::string new_recombination_method = element->GetText();

          try
          {
             set_recombination_method(new_recombination_method);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Mutation method
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("MutationMethod");

       if(element)
       {
          const std::string new_mutation_method = element->GetText();

          try
          {
             set_mutation_method(new_mutation_method);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Elitism size
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ElitismSize");

       if(element)
       {
          const unsigned new_elitism_size = atoi(element->GetText());

          try
          {
             set_elitism_size(new_elitism_size);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Selective pressure
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("SelectivePressure");

       if(element)
       {
          const double new_selective_pressure = atof(element->GetText());

          try
          {
             set_selective_pressure(new_selective_pressure);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Recombination size
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("RecombinationSize");

       if(element)
       {
          const double new_recombination_size = atof(element->GetText());

          try
          {
             set_recombination_size(new_recombination_size);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Mutation rate
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("MutationRate");

       if(element)
       {
          const double new_mutation_rate = atof(element->GetText());

          try
          {
             set_mutation_rate(new_mutation_rate);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Mutation range
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("MutationRange");

       if(element)
       {
          const double new_mutation_range = atof(element->GetText());

          try
          {
             set_mutation_range(new_mutation_range);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Mean performance goal
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("MeanPerformanceGoal");

       if(element)
       {
          const double new_mean_performance_goal = atof(element->GetText());

          try
          {
             set_mean_performance_goal(new_mean_performance_goal);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Standard deviation performance goal
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("StandardDeviationPerformanceGoal");

       if(element)
       {
          const double new_standard_deviation_performance_goal = atof(element->GetText());

          try
          {
             set_standard_deviation_performance_goal(new_standard_deviation_performance_goal);
          }
          catch(const std::logic_error& e)
          {
             std::cout << e.what() << std::endl;
          }
       }
   }

   // Best performance goal
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("BestPerformanceGoal");

       if(element)
       {
          const double new_best_performance_goal = atof(element->GetText());

          try
          {
             set_best_performance_goal(new_best_performance_goal);
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

   // Maximum generations number
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("MaximumGenerationsNumber");

       if(element)
       {
          const unsigned new_maximum_generations_number = atoi(element->GetText());

          try
          {
             set_maximum_generations_number(new_maximum_generations_number);
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
          const unsigned new_maximum_time = atoi(element->GetText());

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

   // Reserve mean norm history
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveMeanNormHistory");

       if(element)
       {
          const bool new_mean_norm_history = atoi(element->GetText());
          set_reserve_mean_norm_history(new_mean_norm_history);
       }
   }

   // Reserve standard deviation norm history
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveStandardDeviationNormHistory");

       if(element)
       {
          const bool new_standard_deviation_norm_history = atoi(element->GetText());
          set_reserve_standard_deviation_norm_history(new_standard_deviation_norm_history);
       }
   }

   // Reserve best norm history
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveBestNormHistory");

       if(element)
       {
          const bool new_best_norm_history = atoi(element->GetText());
          set_reserve_best_norm_history(new_best_norm_history);
       }
   }

   // Reserve mean performance history
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveMeanPerformanceHistory");

       if(element)
       {
          const bool new_mean_performance_history = atoi(element->GetText());
          set_reserve_mean_performance_history(new_mean_performance_history);
       }
   }

   // Reserve standard deviation performance history
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveStandardDeviationPerformanceHistory");

       if(element)
       {
          const bool new_standard_deviation_performance_history = atoi(element->GetText());
          set_reserve_standard_deviation_performance_history(new_standard_deviation_performance_history);
       }
   }

   // Reserve best performance history
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveBestPerformanceHistory");

       if(element)
       {
          const bool new_best_performance_history = atoi(element->GetText());
          set_reserve_best_performance_history(new_best_performance_history);
       }
   }

   // Reserve generalization performance history
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ReserveGeneralizationPerformanceHistory");

       if(element)
       {
          const bool new_generalization_performance_history = atoi(element->GetText());
          set_reserve_generalization_performance_history(new_generalization_performance_history);
       }
   }
}


// void initialize_random(void) method

void EvolutionaryAlgorithm::initialize_random(void)
{
    // Fitness assingment method

    fitness_assignment_method = LinearRanking;

    // Selection method

    selection_method = RouletteWheel;

    // Recombination method

    switch(rand()%2)
   {
      case 0:
      {
         recombination_method = Line;
      }
      break;

      case 1:
      {
         recombination_method = Intermediate;
      }
      break;

      default:
      {
         std::ostringstream buffer;

         buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
                << "void initialize_random(void) method.\n"
                << "Unknown recombination method.\n";

         throw std::logic_error(buffer.str());
      }
      break;
   }

    // Mutation method

    switch(rand()%2)
   {
      case 0:
      {
         mutation_method = Normal;
      }
      break;

      case 1:
      {
         mutation_method = Uniform;
      }
      break;

      default:
      {
         std::ostringstream buffer;

         buffer << "OpenNN Exception: EvolutionaryAlgorithm class.\n"
                << "void initialize_random(void) method.\n"
                << "Unknown mutation method.\n";

         throw std::logic_error(buffer.str());
      }
      break;
   }

    const unsigned new_population_size = (unsigned)calculate_random_uniform(1.0, 11.0)*4;

    set_population_size(new_population_size);
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
