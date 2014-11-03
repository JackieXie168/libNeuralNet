/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   E V O L U T I O N A R Y   A L G O R I T H M   T E S T   C L A S S                                          */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

// System includes

#include <iostream>

// OpenNN includes

#include "../../source/neural_network/neural_network.h"
#include "../../source/training_strategy/evolutionary_algorithm.h"

// Unit testing includees

#include "evolutionary_algorithm_test.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR 

EvolutionaryAlgorithmTest::EvolutionaryAlgorithmTest(void) : UnitTesting()
{
}


// DESTRUCTOR

EvolutionaryAlgorithmTest::~EvolutionaryAlgorithmTest(void)
{
}


// METHODS

// void test_constructor(void) method

void EvolutionaryAlgorithmTest::test_constructor(void)
{
   message += "test_constructor\n"; 

   // Default constructor

   EvolutionaryAlgorithm ea1; 
   assert_true(ea1.get_performance_functional_pointer() == NULL, LOG);   

   // Performance functional constructor

   PerformanceFunctional pf2;

   EvolutionaryAlgorithm ea2(&pf2); 
   assert_true(ea2.get_performance_functional_pointer() != NULL, LOG);   

   NeuralNetwork nn3(1, 1);

   PerformanceFunctional mof3(&nn3);

   EvolutionaryAlgorithm ea3(&mof3); 
   assert_true(ea3.get_performance_functional_pointer() != NULL, LOG);   
}


// void test_destructor(void) method

void EvolutionaryAlgorithmTest::test_destructor(void)
{
}


// void test_get_population_size(void) method

void EvolutionaryAlgorithmTest::test_get_population_size(void)
{
   message += "test_get_population_size\n";

   EvolutionaryAlgorithm ea;

   unsigned int population_size = ea.get_population_size();

   assert_true(population_size == 0, LOG);
}


// void test_get_population(void) method

void EvolutionaryAlgorithmTest::test_get_population(void)
{
   message += "test_get_population\n";

   NeuralNetwork nn(1);
   PerformanceFunctional pf(&nn);
   EvolutionaryAlgorithm ea(&pf);

   ea.set_population_size(4);

   Matrix<double> population = ea.get_population();

   unsigned int rows_number = population.get_rows_number();
   unsigned int columns_number = population.get_columns_number();

   assert_true(rows_number == 4, LOG);
   assert_true(columns_number == 1, LOG);

}


// void test_get_performance(void) method

void EvolutionaryAlgorithmTest::test_get_performance(void)
{
   message += "test_get_performance\n";

   NeuralNetwork nn(1);
   PerformanceFunctional pf(&nn);
   EvolutionaryAlgorithm ea(&pf);

   ea.set_population_size(4);

   Vector<double> evaluation = ea.get_performance();

   unsigned int size = evaluation.size();

   assert_true(size == 4, LOG);

}


// void test_get_fitnesss(void) method

void EvolutionaryAlgorithmTest::test_get_fitness(void)
{
   message += "test_get_fitnesss\n";

   NeuralNetwork nn(1);
   PerformanceFunctional pf(&nn);
   EvolutionaryAlgorithm ea(&pf);

   ea.set_population_size(4);

   Vector<double> fitness = ea.get_fitness();

   unsigned int size = fitness.size();

   assert_true(size == 4, LOG);

}


// void test_get_selection(void) method

void EvolutionaryAlgorithmTest::test_get_selection(void)
{
   message += "test_get_selection\n";

   NeuralNetwork nn(1);
   PerformanceFunctional pf(&nn);
   EvolutionaryAlgorithm ea(&pf);

   ea.set_population_size(4);

   Vector<bool> selection = ea.get_selection();

   unsigned int size = selection.size();

   assert_true(size == 4, LOG);

}


// void test_get_selective_pressure(void) method

void EvolutionaryAlgorithmTest::test_get_selective_pressure(void)
{
   message += "test_get_selective_pressure\n";

   EvolutionaryAlgorithm ea;

   ea.set_fitness_assignment_method(EvolutionaryAlgorithm::LinearRanking);

   ea.set_selective_pressure(1.0);

   assert_true(ea.get_selective_pressure() == 1.0, LOG);

}


// void test_get_recombination_size(void) method

void EvolutionaryAlgorithmTest::test_get_recombination_size(void)
{
   message += "test_get_recombination_size\n";

   EvolutionaryAlgorithm ea;

   ea.set_recombination_size(0.0);

   assert_true(ea.get_recombination_size() == 0.0, LOG);
}


// void test_get_mutation_rate(void) method

void EvolutionaryAlgorithmTest::test_get_mutation_rate(void)
{
   message += "test_get_mutation_rate\n";

   EvolutionaryAlgorithm ea;

   ea.set_mutation_rate(0.0);

   assert_true(ea.get_mutation_rate() == 0.0, LOG);
}


// void test_get_mutation_range(void) method

void EvolutionaryAlgorithmTest::test_get_mutation_range(void)
{
   message += "test_get_mutation_range\n";

   EvolutionaryAlgorithm ea;

   ea.set_mutation_range(0.0);

   assert_true(ea.get_mutation_range() == 0.0, LOG);
}


// void test_get_maximum_generations_number(void) method

void EvolutionaryAlgorithmTest::test_get_maximum_generations_number(void)
{
   message += "test_get_maximum_generations_number\n";

   EvolutionaryAlgorithm ea;

   ea.set_maximum_generations_number(1);

   assert_true(ea.get_maximum_generations_number() == 1, LOG);
}


// void test_get_reserve_population_history(void) method

void EvolutionaryAlgorithmTest::test_get_reserve_population_history(void)
{
   message += "test_get_reserve_population_history\n";

   EvolutionaryAlgorithm ea;

   ea.set_reserve_population_history(true);

   assert_true(ea.get_reserve_population_history() == true, LOG);

   ea.set_reserve_population_history(false);

   assert_true(ea.get_reserve_population_history() == false, LOG);
}


// void test_get_reserve_mean_norm_history(void) method

void EvolutionaryAlgorithmTest::test_get_reserve_mean_norm_history(void)
{
   message += "test_get_reserve_mean_norm_history\n";

   EvolutionaryAlgorithm ea;

   ea.set_reserve_mean_norm_history(true);

   assert_true(ea.get_reserve_mean_norm_history() == true, LOG);

   ea.set_reserve_mean_norm_history(false);

   assert_true(ea.get_reserve_mean_norm_history() == false, LOG);
}


// void test_get_reserve_standard_deviation_norm_history(void) method

void EvolutionaryAlgorithmTest::test_get_reserve_standard_deviation_norm_history(void)
{
   message += "test_get_reserve_standard_deviation_norm_history\n";

   EvolutionaryAlgorithm ea;

   ea.set_reserve_standard_deviation_norm_history(true);

   assert_true(ea.get_reserve_standard_deviation_norm_history() == true, LOG);

   ea.set_reserve_standard_deviation_norm_history(false);

   assert_true(ea.get_reserve_standard_deviation_norm_history() == false, LOG);
}


// void test_get_reserve_best_norm_history(void) method

void EvolutionaryAlgorithmTest::test_get_reserve_best_norm_history(void)
{
   message += "test_get_reserve_best_norm_history\n";

   EvolutionaryAlgorithm ea;

   ea.set_reserve_best_norm_history(true);

   assert_true(ea.get_reserve_best_norm_history() == true, LOG);

   ea.set_reserve_best_norm_history(false);

   assert_true(ea.get_reserve_best_norm_history() == false, LOG);
}


// void test_get_reserve_mean_evaluation_history(void) method

void EvolutionaryAlgorithmTest::test_get_reserve_mean_evaluation_history(void)
{
   message += "test_get_reserve_mean_evaluation_history\n";

   EvolutionaryAlgorithm ea;

   ea.set_reserve_mean_evaluation_history(true);

   assert_true(ea.get_reserve_mean_evaluation_history() == true, LOG);

   ea.set_reserve_mean_evaluation_history(false);

   assert_true(ea.get_reserve_mean_evaluation_history() == false, LOG);
}


// void test_get_reserve_standard_deviation_evaluation_history(void) method

void EvolutionaryAlgorithmTest::test_get_reserve_standard_deviation_evaluation_history(void)
{
   message += "test_get_reserve_standard_deviation_evaluation_history\n";

   EvolutionaryAlgorithm ea;

   ea.set_reserve_standard_deviation_evaluation_history(true);

   assert_true(ea.get_reserve_standard_deviation_evaluation_history() == true, LOG);

   ea.set_reserve_standard_deviation_evaluation_history(false);

   assert_true(ea.get_reserve_standard_deviation_evaluation_history() == false, LOG);
}


// void test_get_reserve_best_evaluation_history(void) method

void EvolutionaryAlgorithmTest::test_get_reserve_best_evaluation_history(void)
{
   message += "test_get_reserve_best_evaluation_history\n";

   EvolutionaryAlgorithm ea;

   ea.set_reserve_best_evaluation_history(true);

   assert_true(ea.get_reserve_best_evaluation_history() == true, LOG);

   ea.set_reserve_best_evaluation_history(false);

   assert_true(ea.get_reserve_best_evaluation_history() == false, LOG);
}


// void test_get_fitness_assignment_method(void) method

void EvolutionaryAlgorithmTest::test_get_fitness_assignment_method(void)
{
   message += "test_get_fitness_assignment_method\n";

   EvolutionaryAlgorithm ea;

   ea.set_fitness_assignment_method(EvolutionaryAlgorithm::LinearRanking);
  
   assert_true(ea.get_fitness_assignment_method() == EvolutionaryAlgorithm::LinearRanking, LOG);
}


// void test_get_selection_method(void) method

void EvolutionaryAlgorithmTest::test_get_selection_method(void)
{
   message += "test_get_selection_method\n";

   EvolutionaryAlgorithm ea;

   ea.set_selection_method(EvolutionaryAlgorithm::RouletteWheel);
  
   assert_true(ea.get_selection_method() == EvolutionaryAlgorithm::RouletteWheel, LOG);

   ea.set_selection_method(EvolutionaryAlgorithm::StochasticUniversalSampling);
  
   assert_true(ea.get_selection_method() == EvolutionaryAlgorithm::StochasticUniversalSampling, LOG);
}


// void test_get_recombination_method(void) method

void EvolutionaryAlgorithmTest::test_get_recombination_method(void)
{
   message += "test_get_recombination_method\n";

   EvolutionaryAlgorithm ea;

   ea.set_recombination_method(EvolutionaryAlgorithm::Line);
  
   assert_true(ea.get_recombination_method() == EvolutionaryAlgorithm::Line, LOG);

   ea.set_recombination_method(EvolutionaryAlgorithm::Intermediate);
  
   assert_true(ea.get_recombination_method() == EvolutionaryAlgorithm::Intermediate, LOG);
}


// void test_get_mutation_method(void) method

void EvolutionaryAlgorithmTest::test_get_mutation_method(void)
{
   message += "test_get_mutation_method\n";

   EvolutionaryAlgorithm ea;

   // Test

   ea.set_mutation_method(EvolutionaryAlgorithm::Normal);
  
   assert_true(ea.get_mutation_method() == EvolutionaryAlgorithm::Normal, LOG);

   // Test

   ea.set_mutation_method(EvolutionaryAlgorithm::Uniform);
  
   assert_true(ea.get_mutation_method() == EvolutionaryAlgorithm::Uniform, LOG);
}


// void test_set(void) method

void EvolutionaryAlgorithmTest::test_set(void)
{
   message += "test_set\n";

}


// void test_set_default(void) method

void EvolutionaryAlgorithmTest::test_set_default(void)
{
   message += "test_set_default\n";

   NeuralNetwork nn;
   PerformanceFunctional pf(&nn);
   EvolutionaryAlgorithm ea(&pf);

   // Test
   
   ea.set_default();
   assert_true(ea.get_population_size() == 0, LOG);

   // Test

   nn.set(1, 1);
   ea.set_default();
   assert_true(ea.get_population_size() == 20, LOG);
}


// void test_set_population_size(void) method

void EvolutionaryAlgorithmTest::test_set_population_size(void)
{
   message += "test_set_population_size\n";

   NeuralNetwork nn(1);
   PerformanceFunctional pf(&nn);
   EvolutionaryAlgorithm ea(&pf);
   
   ea.set_population_size(4);

   assert_true(ea.get_population_size() == 4, LOG);

}


// void test_set_population(void) method

void EvolutionaryAlgorithmTest::test_set_population(void)
{
   message += "test_set_population\n";

   NeuralNetwork nn(1);
   PerformanceFunctional pf(&nn);
   EvolutionaryAlgorithm ea(&pf);

   ea.set_population_size(4);

   unsigned int parameters_number = nn.count_parameters_number();
   unsigned int population_size = ea.get_population_size();

   Matrix<double> population(population_size, parameters_number, 0.0);   

   ea.set_population(population);

   assert_true(ea.get_population() == 0.0, LOG);

}


// void test_set_performance(void) method

void EvolutionaryAlgorithmTest::test_set_performance(void)
{
   message += "test_set_performance\n";

   EvolutionaryAlgorithm ea;

   Vector<double> evaluation;

   ea.set_performance(evaluation);

   assert_true(ea.get_performance() == 0.0, LOG);
}


// void test_set_fitness(void) method

void EvolutionaryAlgorithmTest::test_set_fitness(void)
{
   message += "test_set_fitness\n";

   EvolutionaryAlgorithm ea;

   Vector<double> fitness;

   ea.set_fitness(fitness);

   assert_true(ea.get_fitness() == 0.0, LOG);
}


// void test_set_selection(void) method

void EvolutionaryAlgorithmTest::test_set_selection(void)
{
   message += "test_set_selection\n";

   EvolutionaryAlgorithm ea;

   Vector<double> selection;

   ea.set_fitness(selection);

   assert_true(ea.get_selection() == 0.0, LOG);
}


// void test_set_selective_pressure(void) method

void EvolutionaryAlgorithmTest::test_set_selective_pressure(void)
{
   message += "test_set_selective_pressure\n";

   EvolutionaryAlgorithm ea;

   ea.set_selective_pressure(1.0);

   assert_true(ea.get_selective_pressure() == 1.0, LOG);
}


// void test_set_recombination_size(void) method

void EvolutionaryAlgorithmTest::test_set_recombination_size(void)
{
   message += "test_set_recombination_size\n";

   EvolutionaryAlgorithm ea;

   ea.set_recombination_size(0.0);

   assert_true(ea.get_recombination_size() == 0.0, LOG);
}


// void test_set_mutation_rate(void) method

void EvolutionaryAlgorithmTest::test_set_mutation_rate(void)
{
   message += "test_set_mutation_rate\n";

   EvolutionaryAlgorithm ea;

   ea.set_mutation_rate(0.0);

   assert_true(ea.get_mutation_rate() == 0.0, LOG);
}


// void test_set_mutation_range(void) method

void EvolutionaryAlgorithmTest::test_set_mutation_range(void)
{
   message += "test_set_mutation_range\n";

   EvolutionaryAlgorithm ea;

   ea.set_mutation_range(0.0);

   assert_true(ea.get_mutation_range() == 0.0, LOG);
}


// void test_set_maximum_generations_number(void) method

void EvolutionaryAlgorithmTest::test_set_maximum_generations_number(void)
{
   message += "test_set_maximum_generations_number\n";

   EvolutionaryAlgorithm ea;

   ea.set_maximum_generations_number(1);

   assert_true(ea.get_maximum_generations_number() == 1, LOG);
}


// void test_set_mean_performance_goal(void) method

void EvolutionaryAlgorithmTest::test_set_mean_performance_goal(void)
{
   message += "test_set_mean_performance_goal\n";

   EvolutionaryAlgorithm ea;

   ea.set_mean_performance_goal(1.0);

   assert_true(ea.get_mean_performance_goal() == 1.0, LOG);
}


// void test_set_standard_deviation_performance_goal(void) method

void EvolutionaryAlgorithmTest::test_set_standard_deviation_performance_goal(void)
{
   message += "test_set_standard_deviation_performance_goal\n";

   EvolutionaryAlgorithm ea;

   ea.set_standard_deviation_performance_goal(1.0);

   assert_true(ea.get_standard_deviation_performance_goal() == 1.0, LOG);
}


// void test_set_fitness_assignment_method(void) method

void EvolutionaryAlgorithmTest::test_set_fitness_assignment_method(void)
{
   message += "test_set_fitness_assignment_method\n";
}


// void test_set_selection_method(void) method

void EvolutionaryAlgorithmTest::test_set_selection_method(void)
{
   message += "test_set_selection_method\n";
}


// void test_set_recombination_method(void) method

void EvolutionaryAlgorithmTest::test_set_recombination_method(void)
{
   message += "test_set_recombination_method\n";
}


// void test_set_mutation_method(void) method

void EvolutionaryAlgorithmTest::test_set_mutation_method(void)
{
   message += "test_set_mutation_method\n";
}


// void test_set_reserve_population_history(void) method

void EvolutionaryAlgorithmTest::test_set_reserve_population_history(void)
{
   message += "test_set_reserve_population_history\n";
}


// void test_set_reserve_mean_norm_history(void) method

void EvolutionaryAlgorithmTest::test_set_reserve_mean_norm_history(void)
{
   message += "test_set_reserve_mean_norm_history\n";
}


// void test_set_reserve_standard_deviation_norm_history(void) method

void EvolutionaryAlgorithmTest::test_set_reserve_standard_deviation_norm_history(void)
{
   message += "test_set_reserve_standard_deviation_norm_history\n";
}


// void test_set_reserve_best_norm_history(void) method

void EvolutionaryAlgorithmTest::test_set_reserve_best_norm_history(void)
{
   message += "test_set_reserve_best_norm_history\n";
}


// void test_set_reserve_mean_evaluation_history(void) method

void EvolutionaryAlgorithmTest::test_set_reserve_mean_evaluation_history(void)
{
   message += "test_set_reserve_mean_evaluation_history\n";
}


// void test_set_reserve_standard_deviation_evaluation_history(void) method

void EvolutionaryAlgorithmTest::test_set_reserve_standard_deviation_evaluation_history(void)
{
   message += "test_set_reserve_standard_deviation_evaluation_history\n";
}


// void test_set_reserve_best_evaluation_history(void) method

void EvolutionaryAlgorithmTest::test_set_reserve_best_evaluation_history(void)
{
   message += "test_set_reserve_best_evaluation_history\n";
}


// void test_get_individual(void) method

void EvolutionaryAlgorithmTest::test_get_individual(void)
{
   message += "test_get_individual\n";

   NeuralNetwork nn(1, 1);
   PerformanceFunctional pf(&nn);
   EvolutionaryAlgorithm ea(&pf);

   ea.initialize_population(0.0);

   assert_true(ea.get_individual(0) == 0.0, LOG);

}


// void test_set_individual(void) method

void EvolutionaryAlgorithmTest::test_set_individual(void)
{
   message += "test_set_individual\n";

   NeuralNetwork nn(1, 1);
   PerformanceFunctional pf(&nn);
   EvolutionaryAlgorithm ea(&pf);

   Vector<double> individual(2, 0.0);

   ea.set_individual(0, individual);

   assert_true(ea.get_individual(0) == 0.0, LOG);
}


// void test_initialize_population_uniform(void) method

void EvolutionaryAlgorithmTest::test_initialize_population_uniform(void)
{
   message += "test_initialize_population_uniform\n";

   NeuralNetwork nn(1);
   PerformanceFunctional pf(&nn);
   EvolutionaryAlgorithm ea(&pf);
   
   ea.initialize_population_uniform();

   Matrix<double> population = ea.get_population();

   assert_true(population >=-1  && population <= 1.0, LOG);
}


// void test_initialize_population_normal(void) method

void EvolutionaryAlgorithmTest::test_initialize_population_normal(void)
{
   message += "test_initialize_population_normal\n";
}


// void test_calculate_population_norm(void) method

void EvolutionaryAlgorithmTest::test_calculate_population_norm(void)
{
   message += "test_calculate_population_norm\n";

   NeuralNetwork nn(1);
   PerformanceFunctional pf(&nn);
   EvolutionaryAlgorithm ea(&pf);
   
   ea.initialize_population(0.0);

   assert_true(ea.calculate_population_norm() == 0.0, LOG);
}


// void test_evaluate_population(void) method
// @todo

void EvolutionaryAlgorithmTest::test_evaluate_population(void)
{
   message += "test_evaluate_population\n";

//   NeuralNetwork nn(1, 1);

//   DataSet ds(10, 1, 1);
//   ds.initialize_data(0.0);

//   PerformanceFunctional pf(&nn, &ds);
//   EvolutionaryAlgorithm ea(&pf);
   
//   ea.initialize_population(0.0);

//   ea.evaluate_population();

//   assert_true(ea.get_performance() == 0.0, LOG);
}


// void test_perform_linear_ranking_fitness_assignment(void) method

void EvolutionaryAlgorithmTest::test_perform_linear_ranking_fitness_assignment(void)
{
   message += "test_perform_linear_ranking_fitness_assignment\n";
}


// void test_perform_roulette_wheel_selection(void) method

void EvolutionaryAlgorithmTest::test_perform_roulette_wheel_selection(void)
{
   message += "test_perform_roulette_wheel_selection\n";
}


// void test_perform_stochastic_universal_sampling_selection(void) method

void EvolutionaryAlgorithmTest::test_perform_stochastic_universal_sampling_selection(void)
{
   message += "test_perform_stochastic_universal_sampling_selection\n";
}


// void test_perform_intermediate_recombination(void) method

void EvolutionaryAlgorithmTest::test_perform_intermediate_recombination(void)
{
   message += "test_perform_intermediate_recombination\n";
}


// void test_perform_line_recombination(void) method

void EvolutionaryAlgorithmTest::test_perform_line_recombination(void)
{
   message += "test_perform_line_recombination\n";
}


// void test_perform_normal_mutation(void) method

void EvolutionaryAlgorithmTest::test_perform_normal_mutation(void)
{
   message += "test_perform_normal_mutation\n";
}


// void test_perform_uniform_mutation(void) method

void EvolutionaryAlgorithmTest::test_perform_uniform_mutation(void)
{
   message += "test_perform_uniform_mutation\n";
}


// void test_perform_training(void) method
// @todo

void EvolutionaryAlgorithmTest::test_perform_training(void)
{
   message += "test_perform_training\n";

   NeuralNetwork nn(1, 1);

   DataSet ds(3, 1, 1);
   ds.initialize_data_normal();

   PerformanceFunctional pf(&nn, &ds);

   EvolutionaryAlgorithm ea(&pf);

   nn.initialize_parameters_normal();

//   double old_performance = pf.calculate_evaluation();

   ea.set_display(false);
   ea.set_maximum_generations_number(1);
 //  ea.perform_training();

//   double evaluation = pf.calculate_evaluation();

//   assert_true(evaluation < old_performance, LOG);

   // Performance goal

//   ea.initialize_population_normal();

//   double performance_goal = 1.0;

//   ea.set_performance_goal(performance_goal);
//   ea.set_mean_performance_goal(0.0);
//   ea.set_standard_deviation_performance_goal(0.0);
//   ea.set_maximum_generations_number(1000);
//   ea.set_maximum_time(1000.0);

//   ea.perform_training();

//   evaluation = pf.calculate_evaluation();

//   assert_true(evaluation < performance_goal, LOG);

   // Mean evaluation goal
   
//   ea.initialize_population_uniform(-10.0, 10.0);

//   double mean_performance_goal = 1.0;

//   ea.set_performance_goal(0.0);
//   ea.set_mean_performance_goal(mean_performance_goal);
//   ea.set_standard_deviation_performance_goal(0.0);
//   ea.set_maximum_generations_number(1000);
//   ea.set_maximum_time(1000.0);

//   ea.perform_training();

//   double mean_performance = ea.calculate_mean_performance();

//   assert_true(mean_performance < mean_performance_goal, LOG);
     
   // Standard deviation evaluation goal

//   ea.initialize_population(10.0);

//   double standard_deviation_performance_goal = 1.0;

//   ea.set_performance_goal(0.0);
//   ea.set_mean_performance_goal(0.0);
//   ea.set_standard_deviation_performance_goal(standard_deviation_performance_goal);
//   ea.set_maximum_generations_number(1000);
//   ea.set_maximum_time(1000.0);

//   ea.perform_training();

//   double standard_deviation_performance = ea.calculate_standard_deviation_performance();

//   assert_true(standard_deviation_performance < standard_deviation_performance_goal, LOG);  

}


// void test_to_XML(void) method

void EvolutionaryAlgorithmTest::test_to_XML(void)
{
   message += "test_to_XML\n";

   EvolutionaryAlgorithm ea;
   TiXmlElement* eae = ea.to_XML();

   assert_true(eae != NULL, LOG);  
}


// void test_from_XML(void) method

void EvolutionaryAlgorithmTest::test_from_XML(void)
{
   message += "test_to_XML\n";

//   EvolutionaryAlgorithm ea;
//   TiXmlElement* eae = ea.to_XML();
//   ea.from_XML(eae);
}


// void test_set_reserve_all_training_history(void) method

void EvolutionaryAlgorithmTest::test_set_reserve_all_training_history(void)
{
   message += "test_set_reserve_all_training_history\n";

   EvolutionaryAlgorithm ea;
   ea.set_reserve_all_training_history(true);
}


// void run_test_case(void) method

void EvolutionaryAlgorithmTest::run_test_case(void)
{
   message += "Running evolutionary algorithm test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Get methods

   // Population methods

   test_get_population_size();

   test_get_population();

   test_get_performance();
   test_get_fitness();
   test_get_selection();

   // Training operators

   test_get_fitness_assignment_method();
   test_get_selection_method();
   test_get_recombination_method();
   test_get_mutation_method();

   // Training

   test_get_selective_pressure();
   test_get_recombination_size();
   test_get_mutation_rate();
   test_get_mutation_range();

   test_get_maximum_generations_number();

   test_get_reserve_population_history();
   test_get_reserve_mean_norm_history();
   test_get_reserve_standard_deviation_norm_history();
   test_get_reserve_best_norm_history();
   test_get_reserve_mean_evaluation_history();
   test_get_reserve_standard_deviation_evaluation_history();
   test_get_reserve_best_evaluation_history();

   // Set methods

   test_set();
   test_set_default();

   test_set_population_size();

   test_set_population();

   test_set_performance();
   test_set_fitness();
   test_set_selection();

   test_set_selective_pressure();
   test_set_recombination_size();

   test_set_mutation_rate();
   test_set_mutation_range();

   test_set_maximum_generations_number();
   test_set_mean_performance_goal();
   test_set_standard_deviation_performance_goal();

   test_set_fitness_assignment_method();
   test_set_selection_method();
   test_set_recombination_method();
   test_set_mutation_method();

   test_set_reserve_population_history();
   test_set_reserve_mean_norm_history();
   test_set_reserve_standard_deviation_norm_history();
   test_set_reserve_best_norm_history();
   test_set_reserve_mean_evaluation_history();
   test_set_reserve_standard_deviation_evaluation_history();
   test_set_reserve_best_evaluation_history();

   test_set_reserve_all_training_history();

   // Population methods

   test_get_individual();
   test_set_individual();

   test_initialize_population_uniform();
   test_initialize_population_normal();

   test_calculate_population_norm();

   // Population evaluation methods

   test_evaluate_population();

   // Fitness assignment methods

   test_perform_linear_ranking_fitness_assignment();

   // Selection methods

   test_perform_roulette_wheel_selection();
   test_perform_stochastic_universal_sampling_selection();

   // Recombination methods

   test_perform_intermediate_recombination();
   test_perform_line_recombination();

   // Mutation methods

   test_perform_normal_mutation();
   test_perform_uniform_mutation();

   // Training methods

   test_perform_training();

   // Serialization methods

   test_to_XML();

   message += "End of evolutionary algorithm test case\n";
}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2012 Roberto Lopez 
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
