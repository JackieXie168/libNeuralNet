/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   S I M P L E   P A T T E R N   R E C O G N I T I O N   A P P L I C A T I O N                                */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// This is a pattern recognition problem. 

// System includes

#include <iostream>
#include <sstream>
#include <time.h>
#include <stdexcept>

// OpenNN includes

#include "../../source/opennn.h"

using namespace OpenNN;

int main(void)
{
   try
   {
      std::cout << "OpenNN. Simple Pattern Recognition Application." << std::endl;

      srand( (unsigned)time( NULL ) );

      // Data set object

      DataSet data_set;
      data_set.load_data("../data/simplepatternrecognition.dat");

      Variables* variables_pointer = data_set.get_variables_pointer();

      variables_pointer->set_name(0, "x1");   
      variables_pointer->set_name(1, "x2");   
      variables_pointer->set_name(2, "y");   

      Instances* instances_pointer = data_set.get_instances_pointer();

      instances_pointer->set_training();

      Matrix<std::string> inputs_information = variables_pointer->arrange_inputs_information();
      Matrix<std::string> targets_information = variables_pointer->arrange_targets_information();

      const Vector< Statistics<double> > inputs_statistics = data_set.scale_inputs_minimum_maximum();

      // Neural network object

      NeuralNetwork neural_network(2, 2, 1);

      Inputs* inputs_pointer = neural_network.get_inputs_pointer();

      inputs_pointer->set_information(inputs_information);

      neural_network.construct_scaling_layer();

      ScalingLayer* scaling_layer_pointer = neural_network.get_scaling_layer_pointer();

      scaling_layer_pointer->set_statistics(inputs_statistics);

      scaling_layer_pointer->set_scaling_method(ScalingLayer::NoScaling);

      MultilayerPerceptron* multilayer_perceptron_pointer = neural_network.get_multilayer_perceptron_pointer();

      multilayer_perceptron_pointer->set_layer_activation_function(1, Perceptron::Logistic);

      Outputs* outputs_pointer = neural_network.get_outputs_pointer();

      outputs_pointer->set_information(targets_information);

      // Performance functional
 
      PerformanceFunctional performance_functional(&neural_network, &data_set);

      // Training strategy

      TrainingStrategy training_strategy(&performance_functional);

      QuasiNewtonMethod* quasi_Newton_method_pointer = training_strategy.get_quasi_Newton_method_pointer();

      quasi_Newton_method_pointer->set_minimum_performance_increase(1.0e-4);

	  TrainingStrategy::Results training_stategy_results = training_strategy.perform_training();

      // Testing analysis

      instances_pointer->set_testing();

      TestingAnalysis testing_analysis(&neural_network, &data_set);

      Vector<double> binary_classification_tests = testing_analysis.calculate_binary_classification_tests();

      Matrix<unsigned> confusion = testing_analysis.calculate_confusion();

      // Save results

      scaling_layer_pointer->set_scaling_method(ScalingLayer::MinimumMaximum);

      data_set.save("../data/data_set.xml");
   
      neural_network.save("../data/neural_network.xml");
      neural_network.save_expression("../data/expression.txt");

      performance_functional.save("../data/performance_functional.xml");

      training_strategy.save("../data/training_strategy.xml");
      training_stategy_results.save("../data/training_strategy_results.dat");

      binary_classification_tests.save("../data/binary_classification_tests.dat");
      confusion.save("../data/confusion.dat");

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
