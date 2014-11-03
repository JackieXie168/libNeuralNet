/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   A I R F O I L   S E L F - N O I S E   A P P L I C A T I O N                                                */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// This is a function regression problem.

// System includes

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <time.h>

// OpenNN includes

#include "../../source/opennn.h"

using namespace OpenNN;

int main(void)
{
   try
   {
      std::cout << "OpenNN. Airfoil Self-Noise Application." << std::endl;

      srand((unsigned)time(NULL));

      // Data set

      const std::string data_filename = "../data/airfoil_self_noise.dat";

      DataSet data_set;

      // Data

      data_set.load_data(data_filename);

      // Variables

      Variables* variables_pointer = data_set.get_variables_pointer();

      Vector< Variables::Item > variables_items(6);

      variables_items[0].name = "frequency";
      variables_items[0].units = "hertzs";
      variables_items[0].use = Variables::Input;

      variables_items[1].name = "angle_of_attack";
      variables_items[1].units = "degrees";
      variables_items[1].use = Variables::Input;

      variables_items[2].name = "chord_length";
      variables_items[2].units = "meters";
      variables_items[2].use = Variables::Input;

      variables_items[3].name = "free_stream_velocity";
      variables_items[3].units = "meters per second";
      variables_items[3].use = Variables::Input;

      variables_items[4].name = "suction_side_displacement_thickness";
      variables_items[4].units = "meters";
      variables_items[4].use = Variables::Input;

      variables_items[5].name = "scaled_sound_pressure_level";
      variables_items[5].units = "decibels";
      variables_items[5].use = Variables::Target;

      variables_pointer->set_items(variables_items);

      const Matrix<std::string> inputs_information = variables_pointer->arrange_inputs_information();
      const Matrix<std::string> targets_information = variables_pointer->arrange_targets_information();

      // Instances

      Instances* instances_pointer = data_set.get_instances_pointer();

      instances_pointer->split_random_indices();

      const Vector< Statistics<double> > inputs_statistics = data_set.scale_inputs_minimum_maximum();
      const Vector< Statistics<double> > targets_statistics = data_set.scale_targets_minimum_maximum();

      // Neural network

      const unsigned inputs_number = variables_pointer->count_inputs_number();
      const unsigned hidden_perceptrons_number = 9;
      const unsigned outputs_number = variables_pointer->count_targets_number();

      NeuralNetwork neural_network(inputs_number, hidden_perceptrons_number, outputs_number);

      Inputs* inputs = neural_network.get_inputs_pointer();

      inputs->set_information(inputs_information);

      Outputs* outputs = neural_network.get_outputs_pointer();

      outputs->set_information(targets_information);

      neural_network.construct_scaling_layer();

      ScalingLayer* scaling_layer_pointer = neural_network.get_scaling_layer_pointer();

      scaling_layer_pointer->set_statistics(inputs_statistics);

      scaling_layer_pointer->set_scaling_method(ScalingLayer::NoScaling);

      neural_network.construct_unscaling_layer();

      UnscalingLayer* unscaling_layer_pointer = neural_network.get_unscaling_layer_pointer();

      unscaling_layer_pointer->set_statistics(targets_statistics);

      unscaling_layer_pointer->set_unscaling_method(UnscalingLayer::NoUnscaling);

      // Performance functional

      PerformanceFunctional performance_functional(&neural_network, &data_set);

      performance_functional.set_regularization_type(PerformanceFunctional::NEURAL_PARAMETERS_NORM_REGULARIZATION);

      // Training strategy object

      TrainingStrategy training_strategy(&performance_functional);

      QuasiNewtonMethod* quasi_Newton_method_pointer = training_strategy.get_quasi_Newton_method_pointer();

      quasi_Newton_method_pointer->set_maximum_iterations_number(100);

      quasi_Newton_method_pointer->set_minimum_performance_increase(1.0e-6);

      quasi_Newton_method_pointer->set_reserve_performance_history(true);

      TrainingStrategy::Results training_strategy_results = training_strategy.perform_training();

      // Testing analysis

      TestingAnalysis testing_analysis(&neural_network, &data_set);

      TestingAnalysis::LinearRegressionResults linear_regression_results = testing_analysis.perform_linear_regression_analysis();

      // Save results

      scaling_layer_pointer->set_scaling_method(ScalingLayer::MinimumMaximum);
      unscaling_layer_pointer->set_unscaling_method(UnscalingLayer::MinimumMaximum);

      data_set.save("../data/data_set.xml");

      neural_network.save("../data/neural_network.xml");
      neural_network.save_expression("../data/expression.txt");

      performance_functional.save("../data/performance_functional.xml");

      training_strategy.save("../data/training_strategy.xml");
      training_strategy_results.save("../data/training_strategy_results.dat");

      linear_regression_results.save("../data/linear_regression_analysis_results.dat");

      return(0);
   }
   catch(std::exception& e)
   {
      std::cerr << e.what() << std::endl;

      return(1);
   }
}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2014 Roberto Lopez
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
