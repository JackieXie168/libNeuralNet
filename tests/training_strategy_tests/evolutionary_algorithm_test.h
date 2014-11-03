/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   E V O L U T I O N A R Y   A L G O R I T H M   T E S T   C L A S S   H E A D E R                            */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __EVOLUTIONARYALGORITHMTEST_H__
#define __EVOLUTIONARYALGORITHMTEST_H__

#include "../unit_testing.h"

using namespace OpenNN;

class EvolutionaryAlgorithmTest : public UnitTesting 
{

#define	STRING(x) #x
#define TOSTRING(x) STRING(x)
#define LOG __FILE__ ":" TOSTRING(__LINE__)"\n"

public:

   // GENERAL CONSTRUCTOR

   explicit EvolutionaryAlgorithmTest(void);


   // DESTRUCTOR

   virtual ~EvolutionaryAlgorithmTest(void);


   // METHODS

   // Constructor and destructor methods

   void test_constructor(void);
   void test_destructor(void);

   // Get methods

   void test_get_population_size(void);

   void test_get_population(void);

   void test_get_performance(void);
   void test_get_fitness(void);
   void test_get_selection(void);

   void test_get_selective_pressure(void);
   void test_get_recombination_size(void);
   void test_get_mutation_rate(void);
   void test_get_mutation_range(void);

   void test_get_maximum_generations_number(void);

   void test_get_reserve_population_history(void);
   void test_get_reserve_mean_norm_history(void);
   void test_get_reserve_standard_deviation_norm_history(void);
   void test_get_reserve_best_norm_history(void);
   void test_get_reserve_mean_evaluation_history(void);
   void test_get_reserve_standard_deviation_evaluation_history(void);
   void test_get_reserve_best_evaluation_history(void);

   void test_get_fitness_assignment_method(void);
   void test_get_selection_method(void);
   void test_get_recombination_method(void);
   void test_get_mutation_method(void);

   // Set methods

   void test_set(void);
   void test_set_default(void);

   void test_set_population_size(void);

   void test_set_population(void);

   void test_set_performance(void);
   void test_set_fitness(void);
   void test_set_selection(void);

   void test_set_selective_pressure(void);
   void test_set_recombination_size(void);

   void test_set_mutation_rate(void);
   void test_set_mutation_range(void);

   void test_set_maximum_generations_number(void);
   void test_set_mean_performance_goal(void);
   void test_set_standard_deviation_performance_goal(void);

   void test_set_fitness_assignment_method(void);
   void test_set_selection_method(void);
   void test_set_recombination_method(void);
   void test_set_mutation_method(void);

   void test_set_reserve_population_history(void);
   void test_set_reserve_mean_norm_history(void);
   void test_set_reserve_standard_deviation_norm_history(void);
   void test_set_reserve_best_norm_history(void);
   void test_set_reserve_mean_evaluation_history(void);
   void test_set_reserve_standard_deviation_evaluation_history(void);
   void test_set_reserve_best_evaluation_history(void);

   void test_set_reserve_all_training_history(void);

   // Population methods

   void test_get_individual(void);
   void test_set_individual(void);

   void test_initialize_population_uniform(void);
   void test_initialize_population_normal(void);

   void test_calculate_population_norm(void);

   // Population evaluation methods

   void test_evaluate_population(void);

   // Fitness assignment methods

   void test_perform_linear_ranking_fitness_assignment(void);

   // Selection methods

   void test_perform_roulette_wheel_selection(void);
   void test_perform_stochastic_universal_sampling_selection(void);

   // Recombination methods

   void test_perform_intermediate_recombination(void);
   void test_perform_line_recombination(void);

   // Mutation methods

   void test_perform_normal_mutation(void);
   void test_perform_uniform_mutation(void);

   // Training methods

   void test_perform_training(void);

   // Training history methods

   void test_get_training_history_XML(void);

   // Serialization methods

   void test_to_XML(void);
   void test_from_XML(void);

   // Unit testing methods

   void run_test_case(void);

};

#endif


// OpenNN: An Open Source Neural Networks C++ OpenNN.
// Copyright (C) 2005-2012 Roberto Lopez 
//
// This OpenNN is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This OpenNN is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this OpenNN; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
