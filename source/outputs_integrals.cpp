/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   O U T P U T S   I N T E G R A L S   C L A S S                                                              */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// OpenNN includes

#include "outputs_integrals.h"

namespace OpenNN
{

// DEFAULT CONSTRUCTOR

/// Default constructor. 
/// It creates an outputs integrals performance term not associated to any neural network.
/// It also initializes all the rest of class members to their default values.

OutputsIntegrals::OutputsIntegrals(void) 
 : PerformanceTerm()
{
   set_default();
}


// NEURAL NETWORK CONSTRUCTOR

/// Neural network constructor. 
/// It creates an outputs integrals performance term associated to a neural network.
/// It also initializes all the rest of class members to their default values.
/// @param new_neural_network_pointer Pointer to a neural network object.

OutputsIntegrals::OutputsIntegrals(NeuralNetwork* new_neural_network_pointer) 
: PerformanceTerm(new_neural_network_pointer)
{
   set_default();
}


// XML CONSTRUCTOR

/// XML constructor. 
/// It creates an outputs integrals performance term not associated to any neural network.
/// The class members are loaded from a XML document. 
/// @param outputs_integrals_document Pointer to a TinyXML document with the object data.

OutputsIntegrals::OutputsIntegrals(const tinyxml2::XMLDocument& outputs_integrals_document)
 : PerformanceTerm(outputs_integrals_document)
{
   set_default();

   from_XML(outputs_integrals_document);
}


// DESTRUCTOR

/// Destructor.

OutputsIntegrals::~OutputsIntegrals(void) 
{
}


// const NumericalIntegration& get_numerical_integration(void) const method

/// Returns a constant reference to the numerical integration object inside the outputs integrals object. 

const NumericalIntegration& OutputsIntegrals::get_numerical_integration(void) const
{
   return(numerical_integration);
}


// NumericalIntegration* get_numerical_integration_pointer(void) method

/// Returns a pointer to the numerical integration object inside the outputs integrals object. 

NumericalIntegration* OutputsIntegrals::get_numerical_integration_pointer(void) 
{
   return(&numerical_integration);
}


// const Vector<double>& get_outputs_integrals_weights(void) const method

/// Returns the weights for each integral of the neural network outputs.

const Vector<double>& OutputsIntegrals::get_outputs_integrals_weights(void) const
{
   return(outputs_integrals_weights);
}


// const double& get_output_integral_weight(const unsigned&) const method

/// Returns the weight of a single integral of some neural network output.
/// @param i Index of neural network output. 

const double& OutputsIntegrals::get_output_integral_weight(const unsigned& i) const
{
   return(outputs_integrals_weights[i]);
}


// void set_numerical_integration(const NumericalIntegration&) method

/// Sets a new numerical integration object inside the outputs integral object. 
/// @param new_numerical_integration Numerical integration object. 

void OutputsIntegrals::set_numerical_integration(const NumericalIntegration& new_numerical_integration)
{
   numerical_integration = new_numerical_integration;
}


// void set_outputs_integrals_weights(const Vector<double>&) method

/// Sets new weights for each integral of the neural network outputs.
/// @param new_outputs_integrals_weights Weight values. 

void OutputsIntegrals::set_outputs_integrals_weights(const Vector<double>& new_outputs_integrals_weights)
{
   outputs_integrals_weights = new_outputs_integrals_weights;
}


// void set_output_integral_weight(const unsigned&, const double&) method

/// Sets a new weight for a single integral of the neural network outputs.
/// @param i Index of output. 
/// @param new_output_integral_weight Weight value. 

void OutputsIntegrals::set_output_integral_weight(const unsigned& i, const double& new_output_integral_weight)
{
   outputs_integrals_weights[i] = new_output_integral_weight;
}


// void set_default(void) method

/// Sets the default values for the outputs integrals object: 
/// <ul>
/// <li> Outputs integrals weights: 1 for each neural network output. 
/// <li> Display: true.
/// </ul>

void OutputsIntegrals::set_default(void)
{
   unsigned outputs_number = 0;

   if(neural_network_pointer)
   {
      if(neural_network_pointer->has_multilayer_perceptron())
	  {
         const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();

         outputs_number = multilayer_perceptron_pointer->get_inputs_number();
	  }
   }

   outputs_integrals_weights.set(outputs_number, 1.0);
  
   display = true;
}


// METHODS

// void check(void) const method

/// Checks that there are a neural network and a mathematical model associated to the outputs integrals performance term,
/// and that there is a multilayer perceptron in the neural network. 
/// It also checks that the number of inputs in the neural network is 1. 
/// If some of the above conditions is not hold, the method throws an exception. 

void OutputsIntegrals::check(void) const
{
   std::ostringstream buffer;

   // Neural network stuff

   if(!neural_network_pointer)
   {
      buffer << "OpenNN Exception: OutputsIntegrals class.\n"
             << "void check(void) const method.\n"
             << "Pointer to neural network is NULL.\n";

      throw std::logic_error(buffer.str());	  
   }

   const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();

   if(!multilayer_perceptron_pointer)
   {
      buffer << "OpenNN Exception: OutputsIntegrals class.\n"
             << "void check(void) const method.\n"
             << "Pointer to multilayer perceptron is NULL.\n";

      throw std::logic_error(buffer.str());	  
   }

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   if(inputs_number != 1)
   {
      buffer << "OpenNN Exception: OutputsIntegrals class.\n"
             << "void check(void) const method.\n"
             << "Number of inputs in multilayer perceptron is not one.\n";

      throw std::logic_error(buffer.str());	  
   }

   if(outputs_number == 0)
   {
      buffer << "OpenNN Exception: OutputsIntegrals class.\n"
             << "void check(void) const method.\n"
             << "Number of outputs in multilayer perceptron object is zero.\n";

      throw std::logic_error(buffer.str());	  
   }
}


// double calculate_performance(void) const method

/// Returns the objective value of a multilayer perceptron according to the sum squared error on a data set.
/// @todo

double OutputsIntegrals::calculate_performance(void) const
{
   std::ostringstream buffer;

   buffer << "OpenNN Exception: OutputsIntegrals class.\n"
          << "double calculate_performance(void) const method.\n"
          << "This method is under development.\n";

   throw std::logic_error(buffer.str());	  

/*
   // Control sentence

   #ifndef NDEBUG 

   check();

   #endif

   // Neural network stuff 

   const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();

   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   // Outputs integrals

   double performance = 0;

   for(unsigned i = 0; i < outputs_number; i++)
   {
      performance += 0.0;
   }

   return(performance);
*/
}


// double calculate_performance(const Vector<double>&) const method

/// Returns which would be the performance of a neural network for an hypothetical vector of parameters. 
/// It does not set that vector of parameters to the neural network. 
// @param parameters Vector of potential parameters for the neural network associated to the performance functional.

double OutputsIntegrals::calculate_performance(const Vector<double>&) const
{
   std::ostringstream buffer;

   buffer << "OpenNN Exception: OutputsIntegrals class.\n"
          << "double calculate_performance(const Vector<double>&) const method.\n"
          << "This method is under development.\n";

   throw std::logic_error(buffer.str());	  
/*  
 // Control sentence (if debug)

   #ifndef NDEBUG 

   check();

   #endif

   #ifndef NDEBUG 

   const unsigned size = parameters.size();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   if(size != parameters_number)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: OutputsIntegrals class." << std::endl
             << "double calculate_performance(const Vector<double>&) const method." << std::endl
             << "Size (" << size << ") must be equal to number of parameters (" << parameters_number << ")." << std::endl;

      throw std::logic_error(buffer.str());
   }

   #endif

   NeuralNetwork neural_network_copy(*neural_network_pointer);

   neural_network_copy.set_parameters(parameters);

   OutputsIntegrals sum_squared_error_copy(*this);

   sum_squared_error_copy.set_neural_network_pointer(&neural_network_copy);

   return(sum_squared_error_copy.calculate_performance());
*/
}


// Vector<double> calculate_gradient(void) const method

/// Calculates the objective gradient by means of the back-propagation algorithm, 
/// and returns it in a single vector of size the number of multilayer perceptron parameters. 
/// @todo

Vector<double> OutputsIntegrals::calculate_gradient(void) const
{
   // Neural network stuff

   #ifndef NDEBUG 

   check();

   #endif

   Vector<double> gradient;

   return(gradient);
}


// Matrix<double> calculate_Hessian(void) const method

/// Calculates the objective Hessian by means of the back-propagation algorithm, 
/// and returns it in a single symmetric matrix of size the number of multilayer perceptron parameters. 
/// @todo

Matrix<double> OutputsIntegrals::calculate_Hessian(void) const
{
   // Neural network stuff

   #ifndef NDEBUG 

   check();

   #endif
    
   Matrix<double> Hessian;

   return(Hessian);   
}


// std::string write_performance_term_type(void) const method

/// Returns a string with the name of the outputs integrals performance type, "OUTPUTS_INTEGRALS".

std::string OutputsIntegrals::write_performance_term_type(void) const
{
   return("OUTPUTS_INTEGRALS");
}


// tinyxml2::XMLDocument* to_XML(void) method method 

/// Returns a representation of the sum squared error object, in XML format. 

tinyxml2::XMLDocument* OutputsIntegrals::to_XML(void) const
{
   std::ostringstream buffer;

   tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument;

   // Nueral network outputs integrals

   tinyxml2::XMLElement* outputs_integrals_element = document->NewElement("OutputsIntegrals");

   document->InsertFirstChild(outputs_integrals_element);

   // Numerical differentiation
   
   if(numerical_differentiation_pointer)
   {
	  tinyxml2::XMLElement* element = numerical_differentiation_pointer->to_XML()->FirstChildElement();
      outputs_integrals_element->LinkEndChild(element);
   }

   // Outputs integrals weights
   {
      tinyxml2::XMLElement* element = document->NewElement("OutputsIntegralsWeights");
      outputs_integrals_element->LinkEndChild(element);

      buffer.str("");
      buffer << outputs_integrals_weights;

      tinyxml2::XMLText* text = document->NewText(buffer.str().c_str());
      element->LinkEndChild(text);
   }

   // Display
   {
      tinyxml2::XMLElement* element = document->NewElement("Display");
      outputs_integrals_element->LinkEndChild(element);

      buffer.str("");
      buffer << display;

      tinyxml2::XMLText* text = document->NewText(buffer.str().c_str());
      element->LinkEndChild(text);
   }

   return(document);
}


// void from_XML(const tinyxml2::XMLDocument&) method

/// Loads an outputs integrals object from a XML document.
/// @param document TinyXML document containing the members of this object.

void OutputsIntegrals::from_XML(const tinyxml2::XMLDocument& document)
{
    const tinyxml2::XMLElement* root_element = document.FirstChildElement("OutputsIntegrals");

    if(!root_element)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: OutputsIntegrals class.\n"
               << "void from_XML(const tinyxml2::XMLDocument&) method.\n"
               << "Outputs integrals element is NULL.\n";

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
