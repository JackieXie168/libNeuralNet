/****************************************************************************************************************/
/*                                                                                                              */ 
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   L O G I C A L   O P E R A T O R S   A P P L I C A T I O N                                                  */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */  
/****************************************************************************************************************/

// This is a classical learning problem.

// System includes

#include <iostream>
#include <math.h>
#include <time.h>

// OpenNN includes

#include "../../source/opennn.h"

using namespace OpenNN;

int main(void)
{
   try
   {
      std::cout << "OpenNN. Logical Operations Application." << std::endl;	

      srand((unsigned)time(NULL));

      // Data set

      DataSet data_set;
      
	  data_set.load_data("../data/logical_operations/logical_operations.dat");

	  VariablesInformation* variables_information_pointer = data_set.get_variables_information_pointer();

	  variables_information_pointer->set(2, 6);

      variables_information_pointer->set_name(0, "X");
      variables_information_pointer->set_name(1, "Y");
      variables_information_pointer->set_name(2, "AND");
      variables_information_pointer->set_name(3, "OR");
      variables_information_pointer->set_name(4, "NAND");
      variables_information_pointer->set_name(5, "NOR");
      variables_information_pointer->set_name(6, "XNOR");
      variables_information_pointer->set_name(7, "XNOR");

      const Vector< Vector<std::string> > inputs_targets_information = variables_information_pointer->arrange_inputs_targets_information();

      const Vector< Vector<double> > inputs_targets_statistics = data_set.scale_inputs_targets();
	 
      // Neural network

      NeuralNetwork neural_network(2, 6, 6);
      neural_network.set_inputs_outputs_information(inputs_targets_information);    
      neural_network.set_inputs_outputs_statistics(inputs_targets_statistics); 

      // Performance functional

      PerformanceFunctional performance_functional(&neural_network, &data_set);

      // Training strategy

      TrainingStrategy training_strategy(&performance_functional);

      training_strategy.perform_training();

      neural_network.set_inputs_scaling_outputs_unscaling_methods("MinimumMaximum");

      // Save results

	  data_set.save("../data/logical_operations/data_set.xml");   

      neural_network.save("../data/logical_operations/neural_network.xml");   

      performance_functional.save("../data/logical_operations/performance_functional.xml");   

      training_strategy.save("../data/logical_operations/training_strategy.xml");   

      // Print results to screen

      Vector<double> inputs(2, 0.0);
      Vector<double> outputs(6, 0.0);

      std::cout << "X Y AND OR NAND NOR XOR XNOR" << std::endl;

      inputs[0] = 1.0;
      inputs[1] = 1.0;

      outputs = neural_network.calculate_outputs(inputs);

	  std::cout << inputs.calculate_binary() << " " << outputs.calculate_binary() << std::endl;

      inputs[0] = 1.0;
      inputs[1] = 0.0;

      outputs = neural_network.calculate_outputs(inputs);

	  std::cout << inputs.calculate_binary() << " " << outputs.calculate_binary() << std::endl;

      inputs[0] = 0.0;
      inputs[1] = 1.0;

      outputs = neural_network.calculate_outputs(inputs);

	  std::cout << inputs.calculate_binary() << " " << outputs.calculate_binary() << std::endl;

      inputs[0] = 0.0;
      inputs[1] = 0.0;

      outputs = neural_network.calculate_outputs(inputs);

	  std::cout << inputs.calculate_binary() << " " << outputs.calculate_binary() << std::endl;

      return(0);
   }
   catch(std::exception& e)
   {
      std::cerr << e.what() << std::endl;

      return(1);
   }
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
