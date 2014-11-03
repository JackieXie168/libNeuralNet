/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   C R O S S   E N T R O P Y   E R R O R   C L A S S                                                          */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// OpenNN includes

#include "cross_entropy_error.h"

namespace OpenNN
{

// DEFAULT CONSTRUCTOR

/// Default constructor. 
/// It creates a default cross entropy error performance term object, 
/// which is not associated to any neural network and not measured on any data set.
/// It also initializes all the rest of class members to their default values.

CrossEntropyError::CrossEntropyError(void) : PerformanceTerm()
{
}


// NEURAL NETWORK CONSTRUCTOR

/// Neural network constructor. 
/// It creates a cross entropy error performance term associated to a neural network but not measured on any data set.
/// It also initializes all the rest of class members to their default values.
/// @param new_neural_network_pointer Pointer to a neural network object.

CrossEntropyError::CrossEntropyError(NeuralNetwork* new_neural_network_pointer)
 : PerformanceTerm(new_neural_network_pointer)
{
}


// DATA SET CONSTRUCTOR

/// Data set constructor. 
/// It creates a cross entropy error not associated to any neural network but to be measured on a data set object.
/// It also initializes all the rest of class members to their default values.
/// @param new_data_set_pointer Pointer to a data set object.

CrossEntropyError::CrossEntropyError(DataSet* new_data_set_pointer) 
: PerformanceTerm(new_data_set_pointer)
{
}


// NEURAL NETWORK AND DATA SET CONSTRUCTOR

/// Neural network and data set constructor. 
/// It creates a cross entropy error performance term object associated to a neural network and measured on a data set.
/// It also initializes all the rest of class members to their default values:
/// @param new_neural_network_pointer: Pointer to a neural network object.
/// @param new_data_set_pointer: Pointer to a data set object.

CrossEntropyError::CrossEntropyError(NeuralNetwork* new_neural_network_pointer, DataSet* new_data_set_pointer)
: PerformanceTerm(new_neural_network_pointer, new_data_set_pointer)
{
}


// XML CONSTRUCTOR

/// XML constructor. 
/// It creates a cross entropy error not associated to any neural network and not measured on any data set.
/// It also sets all the rest of class members from a TinyXML document->
/// @param sum_squared_error_document XML document with the class members. 

CrossEntropyError::CrossEntropyError(const tinyxml2::XMLDocument& sum_squared_error_document)
 : PerformanceTerm(sum_squared_error_document)
{
}


// COPY CONSTRUCTOR

/// Copy constructor. 
/// It creates a cross entropy error not associated to any neural network and not measured on any data set.
/// It also sets all the rest of class members from another sum squared error object.
/// @param new_cross_entropy_error Object to be copied. 

CrossEntropyError::CrossEntropyError(const CrossEntropyError& new_cross_entropy_error)
 : PerformanceTerm(new_cross_entropy_error)
{

}


// DESTRUCTOR

/// Destructor.

CrossEntropyError::~CrossEntropyError(void) 
{
}


// ASSIGNMENT OPERATOR

/// Assignment operator. 
/// @param other_cross_entropy_error Object to be copied. 

CrossEntropyError& CrossEntropyError::operator = (const CrossEntropyError& other_cross_entropy_error)
{
   if(this != &other_cross_entropy_error) 
   {
      *neural_network_pointer = *other_cross_entropy_error.neural_network_pointer;
      *data_set_pointer = *other_cross_entropy_error.data_set_pointer;
      display = other_cross_entropy_error.display;
   }

   return(*this);

}

// EQUAL TO OPERATOR

/// Equal to operator. 
/// If compares this object with another object of the same class, and returns true if they are equal, and false otherwise. 
/// @param other_cross_entropy_error Object to be compared with. 

bool CrossEntropyError::operator == (const CrossEntropyError& other_cross_entropy_error) const
{
   if(*neural_network_pointer == *other_cross_entropy_error.neural_network_pointer
   && *mathematical_model_pointer == *other_cross_entropy_error.mathematical_model_pointer
   && display == other_cross_entropy_error.display)    
   {
      return(true);
   }
   else
   {
      return(false);  
   }

}


// METHODS


// void check(void) const method

/// Checks that there are a neural network and a data set associated to the cross entropy error, 
/// and that the numbers of inputs and outputs in the neural network are equal to the numbers of inputs and targets in the data set. 

void CrossEntropyError::check(void) const
{
   std::ostringstream buffer;

   // Neural network stuff

   if(!neural_network_pointer)
   {
      buffer << "OpenNN Exception: CrossEntropyError class.\n"
             << "void check(void) const method.\n"
             << "Pointer to neural network is NULL.\n";

      throw std::logic_error(buffer.str());	  
   }

   const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();

   if(!multilayer_perceptron_pointer)
   {
      buffer << "OpenNN Exception: CrossEntropyError class.\n"
             << "void check(void) const method.\n"
             << "Pointer to multilayer perceptron is NULL.\n";

      throw std::logic_error(buffer.str());	  
   }

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   if(inputs_number == 0)
   {
      buffer << "OpenNN Exception: CrossEntropyError class.\n"
             << "void check(void) const method.\n"
             << "Number of inputs in multilayer perceptron object is zero.\n";

      throw std::logic_error(buffer.str());	  
   }

   if(outputs_number == 0)
   {
      buffer << "OpenNN Exception: CrossEntropyError class.\n"
             << "void check(void) const method.\n"
             << "Number of outputs in multilayer perceptron object is zero.\n";

      throw std::logic_error(buffer.str());	  
   }

   const ProbabilisticLayer* probabilistic_layer_pointer = neural_network_pointer->get_probabilistic_layer_pointer();

   if(!probabilistic_layer_pointer)
   {
      buffer << "OpenNN Exception: CrossEntropyError class.\n"
             << "void check(void) const method.\n"
             << "Pointer to probabilistic layer is NULL.\n";

      throw std::logic_error(buffer.str());	  
   }

   const ProbabilisticLayer::ProbabilisticMethod& outputs_probabilizing_method = probabilistic_layer_pointer->get_probabilistic_method();

   if(outputs_probabilizing_method != ProbabilisticLayer::Softmax)
   {
      buffer << "OpenNN Exception: CrossEntropyError class.\n"
             << "void check(void) const method.\n"
             << "Probabilistic method is not Softmax.\n";

      throw std::logic_error(buffer.str());
   }

   // Data set stuff

   if(!data_set_pointer)
   {
      buffer << "OpenNN Exception: CrossEntropyError class.\n"
             << "void check(void) const method.\n"
             << "Pointer to data set is NULL.\n";

      throw std::logic_error(buffer.str());	  
   }

   // Sum squared error stuff

   const Variables& variables = data_set_pointer->get_variables();

   const unsigned targets_number = variables.count_targets_number();

   if(inputs_number != inputs_number)
   {
      buffer << "OpenNN Exception: CrossEntropyError class.\n"
             << "void check(void) const method.\n"
             << "Number of inputs in multilayer perceptron must be equal to number of inputs in data set.\n";

      throw std::logic_error(buffer.str());	  
   }

   if(outputs_number != targets_number)
   {
      buffer << "OpenNN Exception: CrossEntropyError class.\n"
             << "void check(void) const method.\n"
             << "Number of outputs in multilayer perceptron must be equal to number of targets in data set.\n";

      throw std::logic_error(buffer.str());
   }
}


// double calculate_performance(void) method

/// @todo

double CrossEntropyError::calculate_performance(void) const
{
   std::ostringstream buffer;

   buffer << "OpenNN Exception: CrossEntropyError class.\n"
          << "double calculate_performance(void) method.\n"
          << "This method is under development.\n";

   throw std::logic_error(buffer.str());
/*
   #ifndef NDEBUG 

   check();

   #endif

   // Neural network stuff

   const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   // Data set stuff 

   const Instances& instances = data_set_pointer->get_instances();

   const unsigned training_instances_number = instances.count_training_instances_number();

   // Cross entropy error

   Vector<double> inputs(inputs_number);
   Vector<double> outputs(outputs_number);
   Vector<double> targets(outputs_number);

   double objective = 0.0;

   for(unsigned i = 0; i < training_instances_number; i++)
   {
      // Input vector

	  inputs = data_set_pointer->get_training_input_instance(i);

      // Output vector

      outputs = multilayer_perceptron_pointer->calculate_outputs(inputs);

      // Target vector

      targets = data_set_pointer->get_training_target_instance(i);

      // Cross entropy error

      for(unsigned j = 0; j < outputs_number; j++)
      {
         objective -= targets[j]*log(outputs[j]) + (1.0 - targets[j])*log(1.0 - outputs[j]);
      }
   }

   return(objective);
*/
}



// double calculate_performance(const Vector<double>&) const method

double CrossEntropyError::calculate_performance(const Vector<double>&) const
{
    return(0.0);
}


// double calculate_minimum_performance(void) method

/// Returns the minimum achieveable cross entropy for the training data. 
/// @todo 

double CrossEntropyError::calculate_minimum_performance(void)
{
   return(0.0);
}


// double calculate_generalization_performance(void) const method

/// Returns the cross entropy error of the neural network measured on the generalization instances of the data set.
/// @todo

double CrossEntropyError::calculate_generalization_performance(void) const
{
   // Control sentence

   #ifndef NDEBUG 

   check();

   #endif

   // Neural network stuff

   const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   // Data set stuff

   const Instances& instances = data_set_pointer->get_instances();

   const unsigned generalization_instances_number = instances.count_generalization_instances_number();

   Vector<double> inputs(inputs_number);
   Vector<double> outputs(outputs_number);
   Vector<double> targets(outputs_number);

   double generalization_performance = 0.0;

   for(unsigned i = 0; i < generalization_instances_number; i++)
   {
      // Input vector

	  inputs = data_set_pointer->get_generalization_input_instance(i);

      // Output vector

      outputs = multilayer_perceptron_pointer->calculate_outputs(inputs);

      // Target vector

      targets = data_set_pointer->get_generalization_target_instance(i);

      // Cross entropy error

      for(unsigned j = 0; j < outputs_number; j++)
      {
         generalization_performance -= targets[j]*log(outputs[j]) + (1.0 - targets[j])*log(1.0 - outputs[j]);
      }
   }

   return(generalization_performance);
}


// double calculate_minimum_generalization_performance(void) method

/// Returns the minimum achieveable cross entropy for the generalization data. 
/// @todo

double CrossEntropyError::calculate_minimum_generalization_performance(void)
{
   return(0.0);
}


// Vector<double> calculate_gradient(void) const

/// Returns the cross entropy error gradient of a neural network on a data set. 
/// It uses the error back-propagation method.
/// @todo

Vector<double> CrossEntropyError::calculate_gradient(void) const
{
   #ifndef NDEBUG 

   check();

   #endif

   // Neural network stuff

   const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   const unsigned layers_number = multilayer_perceptron_pointer->get_layers_number();

   const unsigned neural_parameters_number = multilayer_perceptron_pointer->count_parameters_number();

   const bool has_conditions_layer = neural_network_pointer->has_conditions_layer();

   const ConditionsLayer* conditions_layer_pointer = has_conditions_layer ? neural_network_pointer->get_conditions_layer_pointer() : NULL;


   #ifndef NDEBUG 

   std::ostringstream buffer;

   const Matrix<double> target_data = data_set_pointer->arrange_target_data();

   if(target_data < 0.0)
   {
      buffer << "OpenNN Exception: CrossEntropyError class.\n"
             << "Vector<double> calculate_gradient(void) const method.\n"
             << "Target data must be equal or greater than zero.\n";

      throw std::logic_error(buffer.str());
   }

   if(target_data > 1.0)
   {
      buffer << "OpenNN Exception: CrossEntropyError class.\n"
             << "Vector<double> calculate_gradient(void) const method.\n"
             << "Target data must be less or equal or than one.\n";

      throw std::logic_error(buffer.str());
   }

   #endif

   // Neural network stuff    

   Vector< Vector< Vector<double> > > first_order_forward_propagation(2); 

   Vector<double> particular_solution;
   Vector<double> homogeneous_solution;

   // Data set stuff

   const Instances& instances = data_set_pointer->get_instances();

   const unsigned training_instances_number = instances.count_training_instances_number();

   Vector<double> inputs(inputs_number);
   Vector<double> targets(outputs_number);

   // Sum squared error stuff

   Vector<double> output_objective_gradient(outputs_number);

   Vector< Vector<double> > layers_delta; 

   Vector<double> point_gradient(neural_parameters_number, 0.0);

   Vector<double> gradient(neural_parameters_number, 0.0);

   for(unsigned i = 0; i < training_instances_number; i++)
   {
      inputs = data_set_pointer->get_training_input_instance(i);

      targets = data_set_pointer->get_training_target_instance(i);

      first_order_forward_propagation = multilayer_perceptron_pointer->calculate_first_order_forward_propagation(inputs);

      const Vector< Vector<double> >& layers_activation = first_order_forward_propagation[0];
      const Vector< Vector<double> >& layers_activation_derivative = first_order_forward_propagation[1];

      if(!has_conditions_layer)
      {
         const Vector<double>& outputs = layers_activation[layers_number-1];

         for(unsigned j = 0; j < outputs_number; j++)
         {
            //output_objective_gradient[j] = -targets[j]/outputs[j]
            //+ (1.0 - targets[j])*(1.0 - outputs[j]);

            output_objective_gradient[j]
            = -targets[j]/outputs[j] + (1.0 - targets[j])/(1.0 - outputs[j]);

         }

         layers_delta = calculate_layers_delta(layers_activation_derivative, output_objective_gradient);
      }
      else
      {
         particular_solution = conditions_layer_pointer->calculate_particular_solution(inputs);
         homogeneous_solution = conditions_layer_pointer->calculate_homogeneous_solution(inputs);

         const Vector<double>& outputs = particular_solution + homogeneous_solution*layers_activation[layers_number-1];

         for(unsigned j = 0; j < outputs_number; j++)
         {
//            output_objective_gradient[j]
//            = -targets[j]/outputs[j] + (1.0 - targets[j])*(1.0 - outputs[j]);

            output_objective_gradient[j]
            = -targets[j]/outputs[j] + (1.0 - targets[j])*(1.0 - outputs[j]);

         }

		 layers_delta = calculate_layers_delta(layers_activation_derivative, homogeneous_solution, output_objective_gradient);
      }

      point_gradient = calculate_point_gradient(inputs, layers_activation, layers_delta);

      gradient += point_gradient;
   }

   return(gradient);
}


// Matrix<double> calculate_Hessian(void) const

/// @todo

Matrix<double> CrossEntropyError::calculate_Hessian(void) const
{
   Matrix<double> objective_Hessian;

   return(objective_Hessian);
}


// std::string write_performance_term_type(void) const method

/// Returns a string with the name of the cross entropy error performance type, "CROSS_ENTROPY_ERROR".

std::string CrossEntropyError::write_performance_term_type(void) const
{
   return("CROSS_ENTROPY_ERROR");
}


// tinyxml2::XMLDocument* to_XML(void) const method 

/// Serializes the cross entropy error object into a XML document of the TinyXML library. 
/// See the OpenNN manual for more information about the format of this document-> 

tinyxml2::XMLDocument* CrossEntropyError::to_XML(void) const
{
   std::ostringstream buffer;

   tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument;

   // Cross entropy error 

   tinyxml2::XMLElement* cross_entropy_error_element = document->NewElement("CrossEntropyError");

   document->InsertFirstChild(cross_entropy_error_element);

   // Display

   {
      tinyxml2::XMLElement* display_element = document->NewElement("Display");
      cross_entropy_error_element->LinkEndChild(display_element);

      buffer.str("");
      buffer << display;

      tinyxml2::XMLText* display_text = document->NewText(buffer.str().c_str());
      display_element->LinkEndChild(display_text);
   }

   return(document);
}


// void from_XML(const tinyxml2::XMLDocument&) method

/// Deserializes a TinyXML document into this cross entropy object.
/// @param document TinyXML document containing the member data.

void CrossEntropyError::from_XML(const tinyxml2::XMLDocument& document)
{
    const tinyxml2::XMLElement* root_element = document.FirstChildElement("CrossEntropyError");

    if(!root_element)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: CrossEntropyError class.\n"
               << "void from_XML(const tinyxml2::XMLDocument&) method.\n"
               << "Cross entropy error element is NULL.\n";

        throw std::logic_error(buffer.str());
    }

  // Display
  {
     const tinyxml2::XMLElement* display_element = root_element->FirstChildElement("Display");

     if(display_element)
     {
        const std::string new_display_string = display_element->GetText();

        try
        {
           set_display(new_display_string != "0");
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
