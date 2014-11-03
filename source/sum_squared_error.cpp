/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   S U M   S Q U A R E D   E R R O R   C L A S S                                                              */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// OpenNN includes

#include "sum_squared_error.h"

namespace OpenNN
{

// DEFAULT CONSTRUCTOR

/// Default constructor. 
/// It creates a sum squared error performance term not associated to any neural network and not measured on any data set.
/// It also initializes all the rest of class members to their default values.

SumSquaredError::SumSquaredError(void) : PerformanceTerm()
{
}


// NEURAL NETWORK CONSTRUCTOR

/// Neural network constructor. 
/// It creates a sum squared error performance term associated to a neural network but not measured on any data set.
/// It also initializes all the rest of class members to their default values.
/// @param new_neural_network_pointer Pointer to a neural network object.

SumSquaredError::SumSquaredError(NeuralNetwork* new_neural_network_pointer) 
: PerformanceTerm(new_neural_network_pointer)
{
}


// DATA SET CONSTRUCTOR

/// Data set constructor. 
/// It creates a sum squared error not associated to any neural network but to be measured on a data set object.
/// It also initializes all the rest of class members to their default values.
/// @param new_data_set_pointer Pointer to a data set object.

SumSquaredError::SumSquaredError(DataSet* new_data_set_pointer)
: PerformanceTerm(new_data_set_pointer)
{
}


// NEURAL NETWORK AND DATA SET CONSTRUCTOR

/// Neural network and data set constructor. 
/// It creates a sum squared error associated to a neural network and measured on a data set.
/// It also initializes all the rest of class members to their default values.
/// @param new_neural_network_pointer Pointer to a neural network object.
/// @param new_data_set_pointer Pointer to a data set object.

SumSquaredError::SumSquaredError(NeuralNetwork* new_neural_network_pointer, DataSet* new_data_set_pointer)
 : PerformanceTerm(new_neural_network_pointer, new_data_set_pointer)
{
}


// XML CONSTRUCTOR

/// XML constructor. 
/// It creates a sum squared error not associated to any neural network and not measured on any data set.
/// It also sets all the rest of class members from a TinyXML document.
/// @param sum_squared_error_document XML document with the class members.

SumSquaredError::SumSquaredError(const tinyxml2::XMLDocument& sum_squared_error_document)
 : PerformanceTerm(sum_squared_error_document)
{
}



// COPY CONSTRUCTOR

/// Copy constructor. 
/// It creates a sum squared error not associated to any neural network and not measured on any data set.
/// It also sets all the rest of class members from another sum squared error object.
/// @param new_sum_squared_error Object to be copied. 

SumSquaredError::SumSquaredError(const SumSquaredError& new_sum_squared_error)
 : PerformanceTerm(new_sum_squared_error)
{

}


// DESTRUCTOR

/// Destructor.

SumSquaredError::~SumSquaredError(void) 
{
}


// METHODS

// void check(void) const method

/// Checks that there are a neural network and a data set associated to the sum squared error, 
/// and that the numbers of inputs and outputs in the neural network are equal to the numbers of inputs and targets in the data set. 
/// If some of the above conditions is not hold, the method throws an exception. 

void SumSquaredError::check(void) const
{
   std::ostringstream buffer;

   // Neural network stuff

   if(!neural_network_pointer)
   {
      buffer << "OpenNN Exception: SumSquaredError class.\n"
             << "void check(void) const method.\n"
             << "Pointer to neural network is NULL.\n";

      throw std::logic_error(buffer.str());	  
   }

   const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();

   if(!multilayer_perceptron_pointer)
   {
      buffer << "OpenNN Exception: SumSquaredError class.\n"
             << "void check(void) const method.\n"
             << "Pointer to multilayer perceptron is NULL.\n";

      throw std::logic_error(buffer.str());	  
   }

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   // Data set stuff

   if(!data_set_pointer)
   {
      buffer << "OpenNN Exception: SumSquaredError class.\n"
             << "void check(void) const method.\n"
             << "Pointer to data set is NULL.\n";

      throw std::logic_error(buffer.str());	  
   }

   // Sum squared error stuff

   const Variables& variables = data_set_pointer->get_variables();

   const unsigned targets_number = variables.count_targets_number();

   if(inputs_number != inputs_number)
   {
      buffer << "OpenNN Exception: SumSquaredError class.\n"
             << "void check(void) const method.\n"
             << "Number of inputs in multilayer perceptron must be equal to number of inputs in data set.\n";

      throw std::logic_error(buffer.str());	  
   }

   if(outputs_number != targets_number)
   {
      buffer << "OpenNN Exception: SumSquaredError class.\n"
             << "void check(void) const method.\n"
             << "Number of outputs in multilayer perceptron must be equal to number of targets in data set.\n";

      throw std::logic_error(buffer.str());
   }
}


// double calculate_performance(void) const method

/// Returns the performance value of a neural network according to the sum squared error on a data set.

double SumSquaredError::calculate_performance(void) const
{
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

   // Sum squared error stuff

   Vector<double> inputs(inputs_number);
   Vector<double> outputs(outputs_number);
   Vector<double> targets(outputs_number);

   double sum_squared_error = 0.0;

   for(unsigned i = 0; i < training_instances_number; i++)
   {
      // Input vector

	  inputs = data_set_pointer->get_training_input_instance(i);

      // Output vector

      outputs = multilayer_perceptron_pointer->calculate_outputs(inputs);

      // Target vector

      targets = data_set_pointer->get_training_target_instance(i);

      // Sum squared error

	  sum_squared_error += outputs.calculate_sum_squared_error(targets);
   }

   return(sum_squared_error);
}


// double calculate_performance(const Vector<double>&) const method

/// Returns which would be the sum squard error performance of a neural network for an hypothetical vector of parameters. 
/// It does not set that vector of parameters to the neural network. 
/// @param parameters Vector of potential parameters for the neural network associated to the performance term.

double SumSquaredError::calculate_performance(const Vector<double>& parameters) const
{
   // Neural network stuff

   #ifndef NDEBUG 

   check();

   #endif

   // Sum squared error stuff

   #ifndef NDEBUG 

   std::ostringstream buffer;

   const unsigned size = parameters.size();

   const unsigned parameters_number = neural_network_pointer->count_parameters_number();

   if(size != parameters_number)
   {
      buffer << "OpenNN Exception: SumSquaredError class." << std::endl
             << "double calculate_performance(const Vector<double>&) const method." << std::endl
             << "Size (" << size << ") must be equal to number of parameters (" << parameters_number << ")." << std::endl;

      throw std::logic_error(buffer.str());
   }

   #endif

   // Neural network stuff

   const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   // Data set stuff

   const Instances& instances = data_set_pointer->get_instances();

   const unsigned training_instances_number = instances.count_training_instances_number();

   // Sum squared error stuff

   Vector<double> inputs(inputs_number);
   Vector<double> outputs(outputs_number);
   Vector<double> targets(outputs_number);

   double sum_squared_error = 0.0;

   for(unsigned i = 0; i < training_instances_number; i++)
   {
      // Input vector

      inputs = data_set_pointer->get_training_input_instance(i);

      // Output vector

      outputs = multilayer_perceptron_pointer->calculate_outputs(inputs, parameters);

      // Target vector

      targets = data_set_pointer->get_training_target_instance(i);

      // Sum squared error

      sum_squared_error += outputs.calculate_sum_squared_error(targets);
   }

   return(sum_squared_error);
}


// double calculate_generalization_performance(void) const method

/// Returns the sum squared error of the neural network measured on the generalization instances of the data set.

double SumSquaredError::calculate_generalization_performance(void) const
{
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

   // Sum squared error stuff

   Vector<double> inputs(inputs_number);
   Vector<double> outputs(outputs_number);
   Vector<double> targets(outputs_number);

   double generalization_objective = 0.0;

   for(unsigned i = 0; i < generalization_instances_number; i++)
   {
      // Input vector

	  inputs = data_set_pointer->get_generalization_input_instance(i);

      // Output vector

      outputs = multilayer_perceptron_pointer->calculate_outputs(inputs);

      // Target vector

      targets = data_set_pointer->get_generalization_target_instance(i);

      // Sum of squares error

      generalization_objective += outputs.calculate_sum_squared_error(targets);           
   }

   return(generalization_objective);
}


// Vector<double> calculate_gradient(void) const method

/// Calculates the performance term gradient by means of the back-propagation algorithm, 
/// and returns it in a single vector of size the number of neural network parameters. 

Vector<double> SumSquaredError::calculate_gradient(void) const
{
   #ifndef NDEBUG 

   check();

   #endif

   // Neural network stuff

   const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();

   // Neural network stuff

   const bool has_conditions_layer = neural_network_pointer->has_conditions_layer();

   const ConditionsLayer* conditions_layer_pointer = has_conditions_layer ? neural_network_pointer->get_conditions_layer_pointer() : NULL;

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   const unsigned layers_number = multilayer_perceptron_pointer->get_layers_number();

   const unsigned neural_parameters_number = multilayer_perceptron_pointer->count_parameters_number();

   Vector< Vector< Vector<double> > > first_order_forward_propagation(2); 

   Vector<double> particular_solution;
   Vector<double> homogeneous_solution;

   // Data set stuff

   const Instances& instances = data_set_pointer->get_instances();

   const unsigned training_instances_number = instances.count_training_instances_number();

   Vector<double> inputs(inputs_number);
   Vector<double> targets(outputs_number);

   // Sum squared error stuff

   Vector<double> output_gradient(outputs_number);

   Vector< Matrix<double> > layers_combination_parameters_Jacobian; 

   Vector< Vector<double> > layers_inputs(layers_number); 
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

      layers_inputs = multilayer_perceptron_pointer->arrange_layers_input(inputs, layers_activation);

      layers_combination_parameters_Jacobian = multilayer_perceptron_pointer->calculate_layers_combination_parameters_Jacobian(layers_inputs);

      if(!has_conditions_layer)
      {
         output_gradient = (layers_activation[layers_number-1]-targets)*2.0;

         layers_delta = calculate_layers_delta(layers_activation_derivative, output_gradient);
      }
      else
      {
         particular_solution = conditions_layer_pointer->calculate_particular_solution(inputs);
         homogeneous_solution = conditions_layer_pointer->calculate_homogeneous_solution(inputs);

         output_gradient = (particular_solution+homogeneous_solution*layers_activation[layers_number-1] - targets)*2.0;

         layers_delta = calculate_layers_delta(layers_activation_derivative, homogeneous_solution, output_gradient);
      }

      point_gradient = calculate_point_gradient(layers_combination_parameters_Jacobian, layers_delta);

      gradient += point_gradient;
   }

   return(gradient);
}


// Matrix<double> calculate_Hessian(void) const method

/// Calculates the objective Hessian by means of the back-propagation algorithm, 
/// and returns it in a single symmetric matrix of size the number of neural network parameters. 

Matrix<double> SumSquaredError::calculate_Hessian(void) const
{
   #ifndef NDEBUG 

   check();

   #endif

   // Neural network stuff

   const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();

   const bool has_conditions_layer = neural_network_pointer->has_conditions_layer();

   const ConditionsLayer* conditions_layer_pointer = has_conditions_layer ? neural_network_pointer->get_conditions_layer_pointer() : NULL;

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   const unsigned layers_number = multilayer_perceptron_pointer->get_layers_number();

   const unsigned parameters_number = multilayer_perceptron_pointer->count_parameters_number();

   const Vector<unsigned> layers_perceptrons_number = multilayer_perceptron_pointer->arrange_layers_perceptrons_numbers();

   Vector< Vector< Vector<double> > > second_order_forward_propagation(3); 

   Vector < Vector< Vector<double> > > perceptrons_combination_parameters_gradient(layers_number);
   Matrix < Matrix<double> > interlayers_combination_combination_Jacobian;

   Vector<double> particular_solution;
   Vector<double> homogeneous_solution;

   // Data set stuff

   const Instances& instances = data_set_pointer->get_instances();

   const unsigned training_instances_number = instances.count_training_instances_number();

   Vector<double> inputs(inputs_number);
   Vector<double> targets(outputs_number);

   // Sum squared error stuff

   Vector< Vector<double> > layers_delta(layers_number);
   Matrix< Matrix<double> > interlayers_Delta(layers_number, layers_number);

   Vector<double> output_objective_gradient(outputs_number);
   Matrix<double> output_objective_Hessian(outputs_number, outputs_number);

   Matrix<double> objective_Hessian(parameters_number, parameters_number, 0.0);

   for(unsigned i = 0; i < training_instances_number; i++)
   {
      inputs = data_set_pointer->get_training_input_instance(i);

      targets = data_set_pointer->get_training_target_instance(i);

      second_order_forward_propagation = multilayer_perceptron_pointer->calculate_second_order_forward_propagation(inputs);
	  
	  Vector< Vector<double> >& layers_activation = second_order_forward_propagation[0];
	  Vector< Vector<double> >& layers_activation_derivative = second_order_forward_propagation[1];
	  Vector< Vector<double> >& layers_activation_second_derivative = second_order_forward_propagation[2];

	  Vector< Vector<double> > layers_inputs(layers_number);

	  layers_inputs[0] = inputs;

	  for(unsigned j = 1; j < layers_number; j++)
	  {
	     layers_inputs[j] = layers_activation[j-1];
	  }

	  perceptrons_combination_parameters_gradient = multilayer_perceptron_pointer->calculate_perceptrons_combination_parameters_gradient(layers_inputs);

      interlayers_combination_combination_Jacobian = multilayer_perceptron_pointer->calculate_interlayers_combination_combination_Jacobian(inputs);

      if(!has_conditions_layer)
      {
         output_objective_gradient = (layers_activation[layers_number-1] - targets)*2.0;
		 output_objective_Hessian.initialize_diagonal(2.0);

		 layers_delta = calculate_layers_delta(layers_activation_derivative, output_objective_gradient);
         interlayers_Delta = calculate_interlayers_Delta(layers_activation_derivative, layers_activation_second_derivative, interlayers_combination_combination_Jacobian, output_objective_gradient, output_objective_Hessian, layers_delta);
      }
      else
      {
         particular_solution = conditions_layer_pointer->calculate_particular_solution(inputs);
         homogeneous_solution = conditions_layer_pointer->calculate_homogeneous_solution(inputs);

         output_objective_gradient = (particular_solution+homogeneous_solution*layers_activation[layers_number-1] - targets)*2.0;              

		 layers_delta = calculate_layers_delta(layers_activation_derivative, homogeneous_solution, output_objective_gradient);
      }

	  objective_Hessian += calculate_point_Hessian(layers_activation_derivative, perceptrons_combination_parameters_gradient, interlayers_combination_combination_Jacobian, layers_delta, interlayers_Delta);
   }

   return(objective_Hessian);   
}


// Vector<double> calculate_terms(void) const method

/// Calculates the squared error terms for each instance, and returns it in a vector of size the number training instances. 

Vector<double> SumSquaredError::calculate_terms(void) const
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   check();

   #endif

   const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   const Instances& instances = data_set_pointer->get_instances();

   const unsigned training_instances_number = instances.count_training_instances_number();

   Vector<double> performance_terms(training_instances_number);

   Vector<double> inputs(inputs_number);
   Vector<double> outputs(outputs_number);
   Vector<double> targets(outputs_number);

   for(unsigned i = 0; i < training_instances_number; i++)
   {
      // Input vector

	  inputs = data_set_pointer->get_training_input_instance(i);

      // Output vector

      outputs = multilayer_perceptron_pointer->calculate_outputs(inputs);

      // Target vector

      targets = data_set_pointer->get_training_target_instance(i);

      // Error

      performance_terms[i] = outputs.calculate_distance(targets);
   }

   return(performance_terms);
}


// Vector<double> calculate_terms(const Vector<double>&) const method

/// Returns the performance terms vector for a hypotetical vector of parameters. 
/// @param parameters Neural network parameters for which the performance terms vector is to be computed. 

Vector<double> SumSquaredError::calculate_terms(const Vector<double>& parameters) const
{
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

      buffer << "OpenNN Exception: SumSquaredError class." << std::endl
             << "double calculate_terms(const Vector<double>&) const method." << std::endl
             << "Size (" << size << ") must be equal to number of neural network parameters (" << parameters_number << ")." << std::endl;

      throw std::logic_error(buffer.str());	  
   }

   #endif

   NeuralNetwork neural_network_copy(*neural_network_pointer);

   neural_network_copy.set_parameters(parameters);

   SumSquaredError sum_squared_error_copy(*this);

   sum_squared_error_copy.set_neural_network_pointer(&neural_network_copy);

   return(sum_squared_error_copy.calculate_terms());
}


// Matrix<double> calculate_terms_Jacobian(void) const method

/// Returns the terms_Jacobian matrix of the sum squared error function, whose elements are given by the 
/// derivatives of the squared errors data set with respect to the multilayer perceptron parameters.
/// The terms_Jacobian matrix here is computed using a back-propagation algorithm.

Matrix<double> SumSquaredError::calculate_terms_Jacobian(void) const
{
   #ifndef NDEBUG 

   check();

   #endif 

   const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();
   const unsigned layers_number = multilayer_perceptron_pointer->get_layers_number();

   const unsigned neural_parameters_number = multilayer_perceptron_pointer->count_parameters_number();

   Vector< Vector< Vector<double> > > first_order_forward_propagation(2);

   Vector< Vector<double> > layers_inputs(layers_number);
   Vector< Matrix<double> > layers_combination_parameters_Jacobian(layers_number);

   Vector<double> particular_solution;
   Vector<double> homogeneous_solution;

   const bool has_conditions_layer = neural_network_pointer->has_conditions_layer();

   const ConditionsLayer* conditions_layer_pointer = has_conditions_layer ? neural_network_pointer->get_conditions_layer_pointer() : NULL;

   // Data set

   const Instances& instances = data_set_pointer->get_instances();

   const unsigned training_instances_number = instances.count_training_instances_number();

   Vector<double> inputs(inputs_number);
   Vector<double> targets(outputs_number);

   // Objective functional

   Vector<double> term(outputs_number);
   double term_norm;

   Vector<double> output_objective_gradient(outputs_number);

   Vector< Vector<double> > layers_delta(layers_number);
   Vector<double> point_gradient(neural_parameters_number);

   Matrix<double> terms_Jacobian(training_instances_number, neural_parameters_number);

   // Main loop

   for(unsigned i = 0; i < training_instances_number; i++)
   {
      inputs = data_set_pointer->get_training_input_instance(i);

	  targets = data_set_pointer->get_training_target_instance(i);

      first_order_forward_propagation = multilayer_perceptron_pointer->calculate_first_order_forward_propagation(inputs);

      const Vector< Vector<double> >& layers_activation = first_order_forward_propagation[0];
      const Vector< Vector<double> >& layers_activation_derivative = first_order_forward_propagation[1];

	  layers_inputs[0] = inputs;

	  for(unsigned j = 1; j < layers_number; j++)
	  {
	     layers_inputs[j] = layers_activation[j-1];
	  }

	  layers_combination_parameters_Jacobian = multilayer_perceptron_pointer->calculate_layers_combination_parameters_Jacobian(layers_inputs);

      if(!has_conditions_layer)
      {
         const Vector<double>& outputs = first_order_forward_propagation[0][layers_number-1]; 

         term = outputs-targets;
         term_norm = term.calculate_norm();

         if(term_norm == 0.0)
   	     {
	        output_objective_gradient.initialize(0.0);
	     }
         else
	     {
            output_objective_gradient = term/term_norm;	      
	     }

         layers_delta = calculate_layers_delta(layers_activation_derivative, output_objective_gradient);
      }
      else
      {
         particular_solution = conditions_layer_pointer->calculate_particular_solution(inputs);
         homogeneous_solution = conditions_layer_pointer->calculate_homogeneous_solution(inputs);

         const Vector<double>& output_layer_activation = first_order_forward_propagation[0][layers_number-1]; 

         term = (particular_solution+homogeneous_solution*output_layer_activation - targets);              
         term_norm = term.calculate_norm();

         if(term_norm == 0.0)
   	     {
	        output_objective_gradient.initialize(0.0);
	     }
	     else
	     {
            output_objective_gradient = term/term_norm;	      
	     }

		 layers_delta = calculate_layers_delta(layers_activation_derivative, homogeneous_solution, output_objective_gradient);
	  }

      point_gradient = calculate_point_gradient(layers_combination_parameters_Jacobian, layers_delta);

      terms_Jacobian.set_row(i, point_gradient);
  }

   return(terms_Jacobian);
}


// FirstOrderTerms calculate_first_order_terms(void) const method

/// Returns the first order performance of the terms objective function.
/// This is a structure containing the objective terms vector and the objective terms Jacobian. 

PerformanceTerm::FirstOrderTerms SumSquaredError::calculate_first_order_terms(void) const
{
   FirstOrderTerms first_order_terms;

   first_order_terms.terms = calculate_terms();
   first_order_terms.Jacobian = calculate_terms_Jacobian();

   return(first_order_terms);
}


// Vector<double> calculate_squared_errors(void) const method

/// Returns the squared errors of the training instances. 

Vector<double> SumSquaredError::calculate_squared_errors(void) const
{
   // Control sentence (if debug)

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

   Vector<double> squared_errors(training_instances_number);

   Vector<double> inputs(inputs_number);
   Vector<double> outputs(outputs_number);
   Vector<double> targets(outputs_number);

   for(unsigned i = 0; i < training_instances_number; i++)
   {
      // Input vector

	  inputs = data_set_pointer->get_training_input_instance(i);

      // Output vector

      outputs = multilayer_perceptron_pointer->calculate_outputs(inputs);

      // Target vector

      targets = data_set_pointer->get_training_target_instance(i);

      // Error

      squared_errors[i] = outputs.calculate_sum_squared_error(targets);
   }

   return(squared_errors);
}


// Vector<double> calculate_gradient(const Vector<double>&) const method

/// @todo

Vector<double> SumSquaredError::calculate_gradient(const Vector<double>&) const
{
    Vector<double> gradient;

    return(gradient);
}


// Matrix<double> calculate_Hessian(const Vector<double>&) const metod

/// @todo

Matrix<double> SumSquaredError::calculate_Hessian(const Vector<double>&) const
{
    Matrix<double> Hessian;

    return(Hessian);
}


// std::string write_performance_term_type(void) const method

/// Returns a string with the name of the sum squared error performance type, "SUM_SQUARED_ERROR".

std::string SumSquaredError::write_performance_term_type(void) const
{
   return("SUM_SQUARED_ERROR");
}


// tinyxml2::XMLDocument* to_XML(void) method method 

/// Returns a representation of the sum squared error object, in XML format. 

tinyxml2::XMLDocument* SumSquaredError::to_XML(void) const
{
   std::ostringstream buffer;

   tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument;

   // Sum squared error

   tinyxml2::XMLElement* root_element = document->NewElement("SumSquaredError");

   document->InsertFirstChild(root_element);

   // Display

   {
      tinyxml2::XMLElement* display_element = document->NewElement("Display");
      root_element->LinkEndChild(display_element);

      buffer.str("");
      buffer << display;

      tinyxml2::XMLText* display_text = document->NewText(buffer.str().c_str());
      display_element->LinkEndChild(display_text);
   }

   return(document);
}


// void load(const tinyxml2::XMLDocument&) method

/// Loads a sum squared error object from a XML document.
/// @param document TinyXML document containing the members of the object.

void SumSquaredError::from_XML(const tinyxml2::XMLDocument& document)
{
    const tinyxml2::XMLElement* root_element = document.FirstChildElement("SumSquaredError");

    if(!root_element)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: SumSquaredError class.\n"
               << "void from_XML(const tinyxml2::XMLDocument&) method.\n"
               << "Sum squared error element is NULL.\n";

        throw std::logic_error(buffer.str());
    }

  // Display
  {
     const tinyxml2::XMLElement* element = root_element->FirstChildElement("Display");

     if(element)
     {
        const std::string new_display_string = element->GetText();

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
