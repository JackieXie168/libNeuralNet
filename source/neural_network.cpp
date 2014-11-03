/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   N E U R A L   N E T W O R K   C L A S S                                                                    */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// OpenNN includes

#include "neural_network.h"

namespace OpenNN
{

// DEFAULT CONSTRUCTOR

/// Default constructor. 
/// It creates an empty neural network object.
/// All pointers in the object are initialized to NULL. 
/// The rest of members are initialized to their default values.

NeuralNetwork::NeuralNetwork(void)
 : multilayer_perceptron_pointer(NULL)
 , scaling_layer_pointer(NULL)
 , unscaling_layer_pointer(NULL)
 , bounding_layer_pointer(NULL)
 , probabilistic_layer_pointer(NULL)
 , conditions_layer_pointer(NULL)
 , inputs_pointer(NULL)
 , outputs_pointer(NULL)
 , independent_parameters_pointer(NULL)
{
   set_default();
}


// MULTILAYER PERCEPTRON CONSTRUCTOR

/// Multilayer Perceptron constructor. 
/// It creates a neural network object from a given multilayer perceptron. 
/// The rest of pointers are initialized to NULL. 
/// This constructor also initializes the rest of class members to their default values.

NeuralNetwork::NeuralNetwork(const MultilayerPerceptron& new_multilayer_perceptron)
 : multilayer_perceptron_pointer(NULL)
 , scaling_layer_pointer(NULL)
 , unscaling_layer_pointer(NULL)
 , bounding_layer_pointer(NULL)
 , probabilistic_layer_pointer(NULL)
 , conditions_layer_pointer(NULL)
 , inputs_pointer(NULL)
 , outputs_pointer(NULL)
 , independent_parameters_pointer(NULL)
{
   multilayer_perceptron_pointer = new MultilayerPerceptron(new_multilayer_perceptron);

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   inputs_pointer = new Inputs(inputs_number);
   outputs_pointer = new Outputs(outputs_number);

   set_default();
}


// MULTILAYER PERCEPTRON ARCHITECTURE CONSTRUCTOR

/// Multilayer perceptron architecture constructor. 
/// It creates a neural network object with a multilayer perceptron given by its architecture. 
/// The rest of pointers are initialized to NULL.  
/// This constructor also initializes the rest of class members to their default values.
/// @param new_multilayer_perceptron_architecture Vector with the number of inputs and the numbers of perceptrons in each layer. 
/// The size of this vector must be equal to one plus the number of layers.

NeuralNetwork::NeuralNetwork(const Vector<unsigned>& new_multilayer_perceptron_architecture)
 : multilayer_perceptron_pointer(NULL)
 , scaling_layer_pointer(NULL)
 , unscaling_layer_pointer(NULL)
 , bounding_layer_pointer(NULL)
 , probabilistic_layer_pointer(NULL)
 , conditions_layer_pointer(NULL)
 , inputs_pointer(NULL)
 , outputs_pointer(NULL)
 , independent_parameters_pointer(NULL)
{
   multilayer_perceptron_pointer = new MultilayerPerceptron(new_multilayer_perceptron_architecture);

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   inputs_pointer = new Inputs(inputs_number);
   outputs_pointer = new Outputs(outputs_number);

   set(new_multilayer_perceptron_architecture);
}


// ONE LAYER CONSTRUCTOR

/// One layer constructor. 
/// It creates a one-layer perceptron object. 
/// The number of independent parameters is set to zero.  
/// The multilayer perceptron parameters are initialized at random. 
/// @param new_inputs_number Number of inputs in the layer.
/// @param new_perceptrons_number Number of perceptrons in the layer.

NeuralNetwork::NeuralNetwork(const unsigned& new_inputs_number, const unsigned& new_perceptrons_number)
 : multilayer_perceptron_pointer(NULL)
 , scaling_layer_pointer(NULL)
 , unscaling_layer_pointer(NULL)
 , bounding_layer_pointer(NULL)
 , probabilistic_layer_pointer(NULL)
 , conditions_layer_pointer(NULL)
 , inputs_pointer(NULL)
 , outputs_pointer(NULL)
 , independent_parameters_pointer(NULL)
{
   multilayer_perceptron_pointer = new MultilayerPerceptron(new_inputs_number, new_perceptrons_number);

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   inputs_pointer = new Inputs(inputs_number);
   outputs_pointer = new Outputs(outputs_number);

   set_default();
}


// TWO LAYERS CONSTRUCTOR

/// Two layers constructor. 
/// It creates a neural network object with a two layers perceptron. 
/// The rest of pointers of this object are initialized to NULL. 
/// The other members are initialized to their default values. 
/// @param new_inputs_number Number of inputs in the multilayer perceptron
/// @param new_hidden_perceptrons_number Number of neurons in the hidden layer of the multilayer perceptron
/// @param new_output_perceptrons_number Number of outputs neurons.

NeuralNetwork::NeuralNetwork(const unsigned& new_inputs_number, const unsigned& new_hidden_perceptrons_number, const unsigned& new_output_perceptrons_number)
 : multilayer_perceptron_pointer(NULL)
 , scaling_layer_pointer(NULL)
 , unscaling_layer_pointer(NULL)
 , bounding_layer_pointer(NULL)
 , probabilistic_layer_pointer(NULL)
 , conditions_layer_pointer(NULL)
 , inputs_pointer(NULL)
 , outputs_pointer(NULL)
 , independent_parameters_pointer(NULL)
{
   multilayer_perceptron_pointer = new MultilayerPerceptron(new_inputs_number, new_hidden_perceptrons_number, new_output_perceptrons_number);

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   inputs_pointer = new Inputs(inputs_number);
   outputs_pointer = new Outputs(outputs_number);

   set_default();
}


// INDEPENDENT PARAMETERS CONSTRUCTOR

/// Independent parameters constructor. 
/// It creates a neural network with only independent parameters.
/// The independent parameters are initialized at random. 
/// @param new_independent_parameters_number Number of independent parameters associated to the multilayer perceptron

NeuralNetwork::NeuralNetwork(const unsigned& new_independent_parameters_number)
 : multilayer_perceptron_pointer(NULL)
 , scaling_layer_pointer(NULL)
 , unscaling_layer_pointer(NULL)
 , bounding_layer_pointer(NULL)
 , probabilistic_layer_pointer(NULL)
 , conditions_layer_pointer(NULL)
 , inputs_pointer(NULL)
 , outputs_pointer(NULL)
 , independent_parameters_pointer(NULL)
{
   independent_parameters_pointer = new IndependentParameters(new_independent_parameters_number);

   set_default();
}


// FILE CONSTRUCTOR

/// File constructor. 
/// It creates a neural network object by loading its members from an XML-type file.
/// Please be careful with the format of that file, which is specified in the OpenNN manual.
/// @param file_name Name of neural network file.

NeuralNetwork::NeuralNetwork(const std::string& file_name)
 : multilayer_perceptron_pointer(NULL)
 , scaling_layer_pointer(NULL)
 , unscaling_layer_pointer(NULL)
 , bounding_layer_pointer(NULL)
 , probabilistic_layer_pointer(NULL)
 , conditions_layer_pointer(NULL)
 , inputs_pointer(NULL)
 , outputs_pointer(NULL)
 , independent_parameters_pointer(NULL)
{
   load(file_name);
}


// XML CONSTRUCTOR

/// XML constructor. 
/// It creates a neural network object by loading its members from an XML document.
/// @param document TinyXML document containing the neural network data.

NeuralNetwork::NeuralNetwork(const tinyxml2::XMLDocument& document)
 : multilayer_perceptron_pointer(NULL)
 , scaling_layer_pointer(NULL)
 , unscaling_layer_pointer(NULL)
 , bounding_layer_pointer(NULL)
 , probabilistic_layer_pointer(NULL)
 , conditions_layer_pointer(NULL)
 , inputs_pointer(NULL)
 , outputs_pointer(NULL)
 , independent_parameters_pointer(NULL)
{
   from_XML(document);
}


// COPY CONSTRUCTOR

/// Copy constructor. 
/// It creates a copy of an existing neural network object. 
/// @param other_neural_network Neural network object to be copied.

NeuralNetwork::NeuralNetwork(const NeuralNetwork& other_neural_network)
 : multilayer_perceptron_pointer(NULL)
 , scaling_layer_pointer(NULL)
 , unscaling_layer_pointer(NULL)
 , bounding_layer_pointer(NULL)
 , probabilistic_layer_pointer(NULL)
 , conditions_layer_pointer(NULL)
 , inputs_pointer(NULL)
 , outputs_pointer(NULL)
 , independent_parameters_pointer(NULL)
{
   set(other_neural_network);
}


// DESTRUCTOR

/// Destructor.

NeuralNetwork::~NeuralNetwork(void)
{
   delete multilayer_perceptron_pointer;
   delete scaling_layer_pointer;
   delete unscaling_layer_pointer;
   delete bounding_layer_pointer;
   delete probabilistic_layer_pointer;
   delete conditions_layer_pointer;
   delete inputs_pointer;
   delete outputs_pointer;
   delete independent_parameters_pointer;
}


// ASSIGNMENT OPERATOR

/// Assignment operator. 
/// It assigns to this object the members of an existing neural network object.
/// @param other_neural_network Neural network object to be assigned.

NeuralNetwork& NeuralNetwork::operator = (const NeuralNetwork& other_neural_network)
{
   if(this != &other_neural_network) 
   {
      delete_pointers();

      inputs_pointer = new Inputs(*other_neural_network.inputs_pointer);

      outputs_pointer = new Outputs(*other_neural_network.outputs_pointer);

      multilayer_perceptron_pointer = new MultilayerPerceptron(*other_neural_network.multilayer_perceptron_pointer);

      scaling_layer_pointer = new ScalingLayer(*other_neural_network.scaling_layer_pointer);

      unscaling_layer_pointer = new UnscalingLayer(*other_neural_network.unscaling_layer_pointer);

      bounding_layer_pointer = new BoundingLayer(*other_neural_network.bounding_layer_pointer);

      probabilistic_layer_pointer = new ProbabilisticLayer(*other_neural_network.probabilistic_layer_pointer);

      conditions_layer_pointer = new ConditionsLayer(*other_neural_network.conditions_layer_pointer);

      independent_parameters_pointer = new IndependentParameters(*other_neural_network.independent_parameters_pointer);

      display = other_neural_network.display;
   }

   return(*this);
}


// EQUAL TO OPERATOR

/// Equal to operator. 
/// @param other_neural_network Neural network object to be compared with.

bool NeuralNetwork::operator == (const NeuralNetwork& other_neural_network) const
{
   if(*multilayer_perceptron_pointer == *other_neural_network.multilayer_perceptron_pointer
   && *scaling_layer_pointer == *other_neural_network.scaling_layer_pointer
   && *unscaling_layer_pointer == *other_neural_network.unscaling_layer_pointer
   && *bounding_layer_pointer == *other_neural_network.bounding_layer_pointer
   && *probabilistic_layer_pointer == *other_neural_network.probabilistic_layer_pointer
   && *conditions_layer_pointer == *other_neural_network.conditions_layer_pointer
   && *independent_parameters_pointer == *other_neural_network.independent_parameters_pointer
   && *inputs_pointer == *other_neural_network.inputs_pointer
   && *outputs_pointer == *other_neural_network.outputs_pointer
   &&  display == other_neural_network.display)
   {
      return(true);
   }
   else
   {
      return(false);
   }
}


// METHODS

// bool has_multilayer_perceptron(void) const method

/// Returns true if the neural network object has a multilayer perceptron object inside,
/// and false otherwise.

bool NeuralNetwork::has_multilayer_perceptron(void) const
{
    if(multilayer_perceptron_pointer)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}


// bool has_inputs(void) const method

/// Returns true if the neural network object has an inputs object inside,
/// and false otherwise.

bool NeuralNetwork::has_inputs(void) const
{
    if(inputs_pointer)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}


// bool has_outputs(void) const method

/// Returns true if the neural network object has an outputs object inside,
/// and false otherwise.

bool NeuralNetwork::has_outputs(void) const
{
    if(outputs_pointer)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}


// bool has_scaling_layer(void) const method

/// Returns true if the neural network object has a scaling layer object inside,
/// and false otherwise.

bool NeuralNetwork::has_scaling_layer(void) const
{
    if(scaling_layer_pointer)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}


// bool has_unscaling_layer(void) const method

/// Returns true if the neural network object has an unscaling layer object inside,
/// and false otherwise.

bool NeuralNetwork::has_unscaling_layer(void) const
{
    if(unscaling_layer_pointer)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}


// bool has_bounding_layer(void) const method

/// Returns true if the neural network object has a bounding layer object inside,
/// and false otherwise.

bool NeuralNetwork::has_bounding_layer(void) const
{
    if(bounding_layer_pointer)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}


// bool has_probabilistic_layer(void) const method

/// Returns true if the neural network object has a probabilistic layer object inside,
/// and false otherwise.

bool NeuralNetwork::has_probabilistic_layer(void) const
{
    if(probabilistic_layer_pointer)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}


// bool has_conditions_layer(void) const method

/// Returns true if the neural network object has a conditions layer object inside,
/// and false otherwise.

bool NeuralNetwork::has_conditions_layer(void) const
{
    if(conditions_layer_pointer)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}


// bool has_independent_parameters(void) const method

/// Returns true if the neural network object has an independent parameters object inside,
/// and false otherwise.

bool NeuralNetwork::has_independent_parameters(void) const
{
    if(independent_parameters_pointer)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}


// Multilayer perceptron* get_multilayer_perceptron_pointer(void) const method

/// Returns a pointer to the multilayer perceptron composing this neural network.

MultilayerPerceptron* NeuralNetwork::get_multilayer_perceptron_pointer(void) const 
{   
    #ifndef NDEBUG

    if(!multilayer_perceptron_pointer)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: NeuralNetwork class.\n"
               << "MultilayerPerceptron* get_multilayer_perceptron_pointer(void) const method.\n"
               << "Multilayer perceptron pointer is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    #endif

   return(multilayer_perceptron_pointer);
}


// ScalingLayer get_scaling_layer_pointer(void) const method

/// Returns a pointer to the scaling layer composing this neural network.

ScalingLayer* NeuralNetwork::get_scaling_layer_pointer(void) const
{
    #ifndef NDEBUG

    if(!scaling_layer_pointer)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: NeuralNetwork class.\n"
               << "ScalingLayer* get_scaling_layer_pointer(void) const method.\n"
               << "Scaling layer pointer is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    #endif

   return(scaling_layer_pointer);
}


// UnscalingLayer* get_unscaling_layer_pointer(void) const method

/// Returns a pointer to the unscaling layer composing this neural network.

UnscalingLayer* NeuralNetwork::get_unscaling_layer_pointer(void) const
{
    #ifndef NDEBUG

    if(!unscaling_layer_pointer)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: NeuralNetwork class.\n"
               << "UnscalingLayer* get_unscaling_layer_pointer(void) const method.\n"
               << "Unscaling layer pointer is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    #endif

   return(unscaling_layer_pointer);
}


// BoundingLayer* get_bounding_layer_pointer(void) const method

/// Returns a pointer to the bounding layer composing this neural network.

BoundingLayer* NeuralNetwork::get_bounding_layer_pointer(void) const
{
    #ifndef NDEBUG

    if(!bounding_layer_pointer)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: NeuralNetwork class.\n"
               << "BoundingLayer* get_bounding_layer_pointer(void) const method.\n"
               << "Bounding layer pointer is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    #endif

   return(bounding_layer_pointer);
}


// ProbabilisticLayer* get_probabilistic_layer_pointer(void) const method

/// Returns a pointer to the probabilistic layer composing this neural network.

ProbabilisticLayer* NeuralNetwork::get_probabilistic_layer_pointer(void) const
{
    #ifndef NDEBUG

    if(!probabilistic_layer_pointer)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: NeuralNetwork class.\n"
               << "ProbabilisticLayer* get_probabilistic_layer_pointer(void) const method.\n"
               << "Probabilistic layer pointer is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    #endif

   return(probabilistic_layer_pointer);
}


// ConditionsLayer* get_conditions_layer(void) const method

/// Returns a pointer to the conditions layer composing this neural network.

ConditionsLayer* NeuralNetwork::get_conditions_layer_pointer(void) const
{
    #ifndef NDEBUG

    if(!conditions_layer_pointer)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: NeuralNetwork class.\n"
               << "ConditionsLayer* get_conditions_layer_pointer(void) const method.\n"
               << "Conditions layer pointer is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    #endif

   return(conditions_layer_pointer);
}


// Inputs& get_inputs_pointer(void) const method

/// Returns a pointer to the inputs object composing this neural network.

Inputs* NeuralNetwork::get_inputs_pointer(void) const
{
    #ifndef NDEBUG

    if(!inputs_pointer)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: NeuralNetwork class.\n"
               << "Inputs* get_inputs_pointer(void) const method.\n"
               << "Inputs pointer is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    #endif

   return(inputs_pointer);
}


// Inputs& get_outputs_pointer(void) const method

/// Returns a pointer to the outputs object composing this neural network.

Outputs* NeuralNetwork::get_outputs_pointer(void) const
{
    #ifndef NDEBUG

    if(!outputs_pointer)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: NeuralNetwork class.\n"
               << "Outputs* get_outputs_pointer(void) const method.\n"
               << "Outputs pointer is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    #endif

   return(outputs_pointer);
}


// IndependentParameters* get_independent_parameters_pointer(void) const method

/// Returns a pointer to the independent parameters object composing this neural network.

IndependentParameters* NeuralNetwork::get_independent_parameters_pointer(void) const
{
    #ifndef NDEBUG

    if(!independent_parameters_pointer)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: NeuralNetwork class.\n"
               << "IndependentParameters* get_independent_parameters_pointer(void) const method.\n"
               << "Independent parameters pointer is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    #endif

   return(independent_parameters_pointer);
}


// const bool& get_display(void) const method

/// Returns true if messages from this class are to be displayed on the screen, or false if messages
/// from this class are not to be displayed on the screen.

const bool& NeuralNetwork::get_display(void) const
{
   return(display);
}


// void set(void) method

/// This method deletes all the pointers in the neural network.
/// It also sets the rest of members to their default values. 

void NeuralNetwork::set(void)
{
   delete_pointers();

   set_default();
}


// void set(const MultilayerPerceptron&) method

/// This method deletes all the pointers in the neural network and then constructs a copy of an exisiting multilayer perceptron.
/// It also sets the rest of members to their default values. 
/// @param new_multilayer_perceptron Multilayer perceptron object to be copied. 

void NeuralNetwork::set(const MultilayerPerceptron& new_multilayer_perceptron)
{
   delete_pointers();

   multilayer_perceptron_pointer = new MultilayerPerceptron(new_multilayer_perceptron);

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();

   inputs_pointer = new Inputs(inputs_number);

   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   outputs_pointer = new Outputs(outputs_number);

   set_default();
}


// void set(const Vector<unsigned>&) method

/// Sets a new neural network with a given multilayer perceptron architecture.
/// It also sets the rest of members to their default values. 
/// @param new_multilayer_perceptron_architecture Architecture of the multilayer perceptron. 

void NeuralNetwork::set(const Vector<unsigned>& new_multilayer_perceptron_architecture)
{
   delete_pointers();

   multilayer_perceptron_pointer = new MultilayerPerceptron(new_multilayer_perceptron_architecture);

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();

   inputs_pointer = new Inputs(inputs_number);

   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   outputs_pointer = new Outputs(outputs_number);

   set_default();
}


// void set(const unsigned&, const unsigned&) method

/// Sets a new multilayer_perceptron_pointer architecture with one layer and zero independent parameters.
/// It also sets the rest of members to their default values. 
/// @param new_inputs_number Number of inputs.
/// @param new_outputs_number Number of outputs.

void NeuralNetwork::set(const unsigned& new_inputs_number, const unsigned& new_outputs_number)
{
   delete_pointers();

   inputs_pointer = new Inputs(new_inputs_number);

   multilayer_perceptron_pointer = new MultilayerPerceptron(new_inputs_number, new_outputs_number);

   outputs_pointer = new Outputs(new_outputs_number);

   set_default();
}


// void set(const unsigned&, const unsigned&, const unsigned&) method

/// Sets a new multilayer_perceptron_pointer architecture with one hidden layer and zero independent parameters.
/// It also sets the rest of members to their default values. 
/// @param new_inputs_number Number of inputs.
/// @param new_hidden_neurons_number Number of neurons in the hidden layer. 
/// @param new_outputs_number Number of outputs.

void NeuralNetwork::set(const unsigned& new_inputs_number, const unsigned& new_hidden_neurons_number, const unsigned& new_outputs_number)
{
   delete_pointers();

   inputs_pointer = new Inputs(new_inputs_number);

   multilayer_perceptron_pointer = new MultilayerPerceptron(new_inputs_number, new_hidden_neurons_number, new_outputs_number);

   outputs_pointer = new Outputs(new_outputs_number);

   set_default();
}


// void set(const unsigned&) method

/// Sets a null new multilayer_perceptron_pointer architecture a given number of independent parameters.
/// It also sets the rest of members to their default values. 
/// @param new_independent_parameters_number Number of independent_parameters_pointer.

void NeuralNetwork::set(const unsigned& new_independent_parameters_number)
{
   delete_pointers();

   independent_parameters_pointer = new IndependentParameters(new_independent_parameters_number);

   set_default();
}


// void set(const std::string&) method

/// Sets the neural network members by loading them from a XML file.
/// @param file_name Neural network XML file_name.

void NeuralNetwork::set(const std::string& file_name)
{
   delete_pointers();

   load(file_name);
}


// void set(const NeuralNetwork&) method

/// Sets the members of this neural network object with those from other neural network object.
/// @param other_neural_network Neural network object to be copied. 

void NeuralNetwork::set(const NeuralNetwork& other_neural_network)
{
   // Pointers 

   delete_pointers();

   if(other_neural_network.multilayer_perceptron_pointer)
   {
      multilayer_perceptron_pointer = new MultilayerPerceptron(*other_neural_network.multilayer_perceptron_pointer);
   }

   if(other_neural_network.scaling_layer_pointer)
   {
      scaling_layer_pointer = new ScalingLayer(*other_neural_network.scaling_layer_pointer);
   }

   if(other_neural_network.unscaling_layer_pointer)
   {
      unscaling_layer_pointer = new UnscalingLayer(*other_neural_network.unscaling_layer_pointer);
   }

   if(other_neural_network.bounding_layer_pointer)
   {
      bounding_layer_pointer = new BoundingLayer(*other_neural_network.bounding_layer_pointer);
   }

   if(other_neural_network.probabilistic_layer_pointer)
   {
      probabilistic_layer_pointer = new ProbabilisticLayer(*other_neural_network.probabilistic_layer_pointer);
   }

   if(other_neural_network.conditions_layer_pointer)
   {
      conditions_layer_pointer = new ConditionsLayer(*other_neural_network.conditions_layer_pointer);
   }

   if(other_neural_network.inputs_pointer)
   {
      inputs_pointer = new Inputs(*other_neural_network.inputs_pointer);
   }

   if(other_neural_network.outputs_pointer)
   {
      outputs_pointer = new Outputs(*other_neural_network.outputs_pointer);
   }

   if(other_neural_network.independent_parameters_pointer)
   {
      independent_parameters_pointer = new IndependentParameters(*other_neural_network.independent_parameters_pointer);
   }

   // Other

   display = other_neural_network.display;
}


// void set_default(void) method

/// Sets those members which are not pointer to their default values.

void NeuralNetwork::set_default(void)
{
   display = true;
}


// void set_multilayer_perceptron_pointer(MultilayerPerceptron*) method

/// Sets a new multilayer perceptron within the neural network.
/// @param new_multilayer_perceptron_pointer Pointer to a multilayer perceptron object. 
/// Note that the neural network destructror will delete this pointer. 

void NeuralNetwork::set_multilayer_perceptron_pointer(MultilayerPerceptron* new_multilayer_perceptron_pointer)
{
   if(new_multilayer_perceptron_pointer != multilayer_perceptron_pointer)
   {
      delete multilayer_perceptron_pointer;

      multilayer_perceptron_pointer = new_multilayer_perceptron_pointer;
   }
}


// void set_scaling_layer_pointer(ScalingLayer*) method

/// Sets a new scaling layer within the neural network.
/// @param new_scaling_layer_pointer Pointer to a scaling layer object. 
/// Note that the neural network destructror will delete this pointer. 

void NeuralNetwork::set_scaling_layer_pointer(ScalingLayer* new_scaling_layer_pointer)
{
   if(new_scaling_layer_pointer != scaling_layer_pointer)
   {
      delete scaling_layer_pointer;

      scaling_layer_pointer = new_scaling_layer_pointer;
   }
}


// void set_unscaling_layer_pointer(UnscalingLayer*) method

/// Sets a new unscaling layer within the neural network.
/// @param new_unscaling_layer_pointer Pointer to an unscaling layer object. 
/// Note that the neural network destructror will delete this pointer. 

void NeuralNetwork::set_unscaling_layer_pointer(UnscalingLayer* new_unscaling_layer_pointer)
{
   if(new_unscaling_layer_pointer != unscaling_layer_pointer)
   {
      delete unscaling_layer_pointer;

      unscaling_layer_pointer = new_unscaling_layer_pointer;
   }
}


// void set_bounding_layer_pointer(BoundingLayer*) method

/// Sets a new bounding layer within the neural network.
/// @param new_bounding_layer_pointer Pointer to a bounding layer object. 
/// Note that the neural network destructror will delete this pointer. 

void NeuralNetwork::set_bounding_layer_pointer(BoundingLayer* new_bounding_layer_pointer)
{
   if(new_bounding_layer_pointer != bounding_layer_pointer)
   {
      delete bounding_layer_pointer;

      bounding_layer_pointer = new_bounding_layer_pointer;
   }
}


// void set_probabilistic_layer_pointer(ProbabilisticLayer*) method

/// Sets a new probabilistic layer within the neural network.
/// @param new_probabilistic_layer_pointer Pointer to a probabilistic layer object. 
/// Note that the neural network destructror will delete this pointer. 

void NeuralNetwork::set_probabilistic_layer_pointer(ProbabilisticLayer* new_probabilistic_layer_pointer)
{
   if(new_probabilistic_layer_pointer != probabilistic_layer_pointer)
   {
      delete probabilistic_layer_pointer;

      probabilistic_layer_pointer = new_probabilistic_layer_pointer;
   }
}


// void set_conditions_layer_pointer(ConditionsLayer*) method

/// Sets a new conditions layer within the neural network.
/// @param new_conditions_layer_pointer Pointer to a conditions layer object. 
/// Note that the neural network destructror will delete this pointer. 

void NeuralNetwork::set_conditions_layer_pointer(ConditionsLayer* new_conditions_layer_pointer)
{
   if(new_conditions_layer_pointer != conditions_layer_pointer)
   {
      delete conditions_layer_pointer;

      conditions_layer_pointer = new_conditions_layer_pointer;
   }
}


// void set_inputs_pointer(Inputs*) method

/// Sets a new inputs object within the neural network.
/// @param new_inputs_pointer Pointer to an inputs object.
/// Note that the neural network destructror will delete this pointer. 

void NeuralNetwork::set_inputs_pointer(Inputs* new_inputs_pointer)
{
   if(new_inputs_pointer != inputs_pointer)
   {
      delete inputs_pointer;

      inputs_pointer = new_inputs_pointer;
   }
}


// void set_outputs_pointer(Outputs*) method

/// Sets a new outputs object within the neural network.
/// @param new_outputs_pointer Pointer to an outputs object.
/// Note that the neural network destructror will delete this pointer.

void NeuralNetwork::set_outputs_pointer(Outputs* new_outputs_pointer)
{
   if(new_outputs_pointer != outputs_pointer)
   {
      delete outputs_pointer;

      outputs_pointer = new_outputs_pointer;
   }
}


// void set_independent_parameters_pointer(IndependentParameters*) method

/// Sets new independent parameters within the neural network.
/// @param new_independent_parameters_pointer Pointer to an independent parameters object. 
/// Note that the neural network destructror will delete this pointer. 

void NeuralNetwork::set_independent_parameters_pointer(IndependentParameters* new_independent_parameters_pointer)
{
   if(new_independent_parameters_pointer != independent_parameters_pointer)
   {
      delete independent_parameters_pointer;

      independent_parameters_pointer = new_independent_parameters_pointer;
   }
}


// unsigned get_inputs_number(void) const method

/// Returns the number of inputs to the neural network.

unsigned NeuralNetwork::get_inputs_number(void) const
{
    unsigned inputs_number;

    if(scaling_layer_pointer)
    {
       inputs_number = scaling_layer_pointer->get_scaling_neurons_number();
    }
    else if(multilayer_perceptron_pointer)
    {
       inputs_number = multilayer_perceptron_pointer->get_inputs_number();
    }
    else if(conditions_layer_pointer)
    {
       inputs_number = conditions_layer_pointer->get_external_inputs_number();
    }
    else if(unscaling_layer_pointer)
    {
       inputs_number = unscaling_layer_pointer->get_unscaling_neurons_number();
    }
    else if(probabilistic_layer_pointer)
    {
       inputs_number = probabilistic_layer_pointer->get_probabilistic_neurons_number();
    }
    else if(bounding_layer_pointer)
    {
       inputs_number = bounding_layer_pointer->get_bounding_neurons_number();
    }
    else
    {
        inputs_number = 0;
    }

    return(inputs_number);
}


// Vector<unsigned> arrange_architecture(void) const

/// Returns a vector with the architecture of the neural network.
/// The elements of this vector are as follows;
/// <UL>
/// <LI> Number of scaling neurons (if there is a scaling layer).</LI>
/// <LI> Multilayer perceptron architecture (if there is a multilayer perceptron).</LI>
/// <LI> Number of conditions neurons (if there is a conditions layer).</LI>
/// <LI> Number of unscaling neurons (if there is an unscaling layer).</LI>
/// <LI> Number of probabilistic neurons (if there is a probabilistic layer).</LI>
/// <LI> Number of bounding neurons (if there is a bounding layer).</LI>
/// </UL>

Vector<unsigned> NeuralNetwork::arrange_architecture(void) const
{
    Vector<unsigned> architecture;

    const unsigned inputs_number = get_inputs_number();

    if(inputs_number == 0)
    {
        return(architecture);
    }

    architecture.push_back(inputs_number);

    // Scaling layer

    if(scaling_layer_pointer)
    {
       architecture.push_back(scaling_layer_pointer->get_scaling_neurons_number());
    }

    // Multilayer perceptron

    if(multilayer_perceptron_pointer)
    {
        architecture = architecture.assemble(multilayer_perceptron_pointer->arrange_layers_perceptrons_numbers());
    }

    // Conditions

    if(conditions_layer_pointer)
    {
       architecture.push_back(conditions_layer_pointer->get_conditions_neurons_number());
    }

    // Unscaling layer

    if(unscaling_layer_pointer)
    {
       architecture.push_back(unscaling_layer_pointer->get_unscaling_neurons_number());
    }

    // Probabilistic layer

    if(probabilistic_layer_pointer)
    {
       architecture.push_back(probabilistic_layer_pointer->get_probabilistic_neurons_number());
    }

    // Bounding layer

    if(bounding_layer_pointer)
    {
       architecture.push_back(bounding_layer_pointer->get_bounding_neurons_number());
    }

    return(architecture);
}


// unsigned count_parameters_number(void) const method

/// Returns the number of parameters in the multilayer perceptron
/// The number of parameters is the sum of all the multilayer perceptron parameters (biases and synaptic weights) and independent parameters.

unsigned NeuralNetwork::count_parameters_number(void) const
{
   unsigned parameters_number = 0;

   if(multilayer_perceptron_pointer)
   {
      parameters_number += multilayer_perceptron_pointer->count_parameters_number();
   }

   if(independent_parameters_pointer)
   {
      parameters_number += independent_parameters_pointer->get_parameters_number();
   }
 
   return(parameters_number);
}
 

// Vector<double> arrange_parameters(void) const method

/// Returns the values of the parameters in the multilayer perceptron as a single vector.
/// This contains all the multilayer perceptron parameters (biases and synaptic weights) and preprocessed independent parameters.

Vector<double> NeuralNetwork::arrange_parameters(void) const 
{
   // Only network parameters 

   if(multilayer_perceptron_pointer && !independent_parameters_pointer)
   {
      return(multilayer_perceptron_pointer->arrange_parameters());
   }

   // Only independent parameters

   else if(!multilayer_perceptron_pointer && independent_parameters_pointer)
   {
      return(independent_parameters_pointer->calculate_scaled_parameters());
   }

   // Both neural and independent parameters

   else if(multilayer_perceptron_pointer && independent_parameters_pointer)
   {
      const Vector<double> network_parameters = multilayer_perceptron_pointer->arrange_parameters();

      const Vector<double> scaled_independent_parameters = independent_parameters_pointer->calculate_scaled_parameters();

      return(network_parameters.assemble(scaled_independent_parameters));
   }

   // None neural neither independent parameters

   else 
   {
      const Vector<double> parameters;

      return(parameters);
   }
}


// void set_parameters(const Vector<double>&) method

/// Sets all the parameters (multilayer_perceptron_pointer parameters and independent parameters) from a single vector.
/// @param new_parameters New set of parameter values. 

void NeuralNetwork::set_parameters(const Vector<double>& new_parameters)
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   const unsigned size = new_parameters.size();

   const unsigned parameters_number = count_parameters_number();

   if(size != parameters_number)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "void set_parameters(const Vector<double>&) method.\n"
             << "Size must be equal to number of parameters.\n";

	  throw std::logic_error(buffer.str());
   }

   #endif

   if(multilayer_perceptron_pointer && !independent_parameters_pointer)
   {// Only network parameters

      multilayer_perceptron_pointer->set_parameters(new_parameters);
   }
   else if(!multilayer_perceptron_pointer && independent_parameters_pointer)
   {// Only independent parameters

       independent_parameters_pointer->unscale_parameters(new_parameters);
   }
   else if(multilayer_perceptron_pointer && independent_parameters_pointer)
   {// Both network and independent parameters

      // Multilayer perceptron parameters

      const unsigned neural_parameters_number = multilayer_perceptron_pointer->count_parameters_number();
      const unsigned independent_parameters_number = independent_parameters_pointer->get_parameters_number();

      const Vector<double> network_parameters = new_parameters.take_out(0, neural_parameters_number);

      multilayer_perceptron_pointer->set_parameters(network_parameters);

      // Independent parameters

      const Vector<double> scaled_independent_parameters = new_parameters.take_out(neural_parameters_number, independent_parameters_number);

      independent_parameters_pointer->unscale_parameters(scaled_independent_parameters);
   }
   else 
   {// None neural neither independent parameters

      return;
   }
}


// void delete_pointers(void) method

/// This method deletes all the pointers composing the neural network:
/// <ul>
/// <li> Inputs.
/// <li> Outputs.
/// <li> Multilayer perceptron.
/// <li> Scaling layer.
/// <li> Unscaling layer.
/// <li> Bounding layer.
/// <li> Probabilistic layer. 
/// <li> Conditions layer. 
/// <li> Independent parameters. 
/// </ul>

void NeuralNetwork::delete_pointers(void)
{
   delete multilayer_perceptron_pointer;
   delete scaling_layer_pointer;
   delete unscaling_layer_pointer;
   delete bounding_layer_pointer;
   delete probabilistic_layer_pointer;
   delete conditions_layer_pointer;
   delete inputs_pointer;
   delete outputs_pointer;
   delete independent_parameters_pointer;

   multilayer_perceptron_pointer = NULL;
   scaling_layer_pointer = NULL;
   unscaling_layer_pointer = NULL;
   bounding_layer_pointer = NULL;
   probabilistic_layer_pointer = NULL;
   conditions_layer_pointer = NULL;
   inputs_pointer = NULL;
   outputs_pointer = NULL;
   independent_parameters_pointer = NULL;
}


// void construct_multilayer_perceptron(void) method

/// This method constructs an empty multilayer perceptron within the neural network. 

void NeuralNetwork::construct_multilayer_perceptron(void)
{
   if(!multilayer_perceptron_pointer)
   {
      multilayer_perceptron_pointer = new MultilayerPerceptron();
   }
}


// void construct_scaling_layer(void) method

/// This method constructs a scaling layer within the neural network. 
/// The size of the scaling layer is the number of inputs in the multilayer perceptron. 

void NeuralNetwork::construct_scaling_layer(void)
{
   if(!scaling_layer_pointer)
   {
      unsigned inputs_number = 0;

      if(multilayer_perceptron_pointer)
      {
         inputs_number = multilayer_perceptron_pointer->get_inputs_number();
      }

      scaling_layer_pointer = new ScalingLayer(inputs_number);
   }
}


// void construct_unscaling_layer(void) method

/// This method constructs an unscaling layer within the neural network. 
/// The size of the unscaling layer is the number of outputs in the multilayer perceptron. 

void NeuralNetwork::construct_unscaling_layer(void)
{
   if(!unscaling_layer_pointer)
   {
      unsigned outputs_number = 0;

      if(multilayer_perceptron_pointer)
      {
         outputs_number = multilayer_perceptron_pointer->get_outputs_number();
      }

      unscaling_layer_pointer = new UnscalingLayer(outputs_number);
   }
}


// void construct_bounding_layer(void) method

/// This method constructs a bounding layer within the neural network. 
/// The size of the bounding layer is the number of outputs in the multilayer perceptron. 

void NeuralNetwork::construct_bounding_layer(void)
{
   if(!bounding_layer_pointer)
   {
      unsigned outputs_number = 0;

      if(multilayer_perceptron_pointer)
      {
         outputs_number = multilayer_perceptron_pointer->get_outputs_number();
      }

      bounding_layer_pointer = new BoundingLayer(outputs_number);
   }
}


// void construct_probabilistic_layer(void) method

/// This method constructs a probabilistic layer within the neural network. 
/// The size of the probabilistic layer is the number of outputs in the multilayer perceptron. 

void NeuralNetwork::construct_probabilistic_layer(void)
{
   if(!probabilistic_layer_pointer)
   {
      unsigned outputs_number = 0;

      if(multilayer_perceptron_pointer)
      {
         outputs_number = multilayer_perceptron_pointer->get_outputs_number();
      }

      probabilistic_layer_pointer = new ProbabilisticLayer(outputs_number);
   }
}


// void construct_conditions_layer(void) method

/// This method constructs a conditions layer within the neural network. 
/// The number of external inputs in the conditions layer is the number of inputs in the multilayer perceptron. 
/// The size fo the conditions layer is the number of outputs in the multilayer perceptron. 

void NeuralNetwork::construct_conditions_layer(void)
{
   if(!conditions_layer_pointer)
   {
      unsigned inputs_number = 0;
      unsigned outputs_number = 0;

      if(multilayer_perceptron_pointer)
      {
         inputs_number = multilayer_perceptron_pointer->get_inputs_number();
         outputs_number = multilayer_perceptron_pointer->get_outputs_number();
      }

      conditions_layer_pointer = new ConditionsLayer(inputs_number, outputs_number);
   }
}


// void construct_inputs(void) method

/// This method constructs an inputs object within the neural network.
/// The number of inputs is the number of inputs in the multilayer perceptron. 

void NeuralNetwork::construct_inputs(void)
{
   if(!inputs_pointer)
   {
      unsigned inputs_number = 0;

      if(multilayer_perceptron_pointer)
      {
         inputs_number = multilayer_perceptron_pointer->get_inputs_number();
      }

      inputs_pointer = new Inputs(inputs_number);
   }
}


// void construct_outputs(void) method

/// This method constructs an outputs object within the neural network.
/// The number of outputs is the number of outputs in the multilayer perceptron.

void NeuralNetwork::construct_outputs(void)
{
   if(!outputs_pointer)
   {
      unsigned outputs_number = 0;

      if(multilayer_perceptron_pointer)
      {
         outputs_number = multilayer_perceptron_pointer->get_outputs_number();
      }

      outputs_pointer = new Outputs(outputs_number);
   }
}


// void construct_independent_parameters(void) method

/// This method constructs an independent parameters object within the neural network. 
/// It sets the number of parameters to zero. 

void NeuralNetwork::construct_independent_parameters(void)
{
   if(!independent_parameters_pointer)
   {
      independent_parameters_pointer = new IndependentParameters();
   }
}


// void destruct_multilayer_perceptron(void) method

/// This method deletes the multilayer perceptron within the neural network. 

void NeuralNetwork::destruct_multilayer_perceptron(void)
{
   delete multilayer_perceptron_pointer;

   multilayer_perceptron_pointer = NULL;
}


// void destruct_scaling_layer(void) method

/// This method deletes the scaling layer within the neural network. 

void NeuralNetwork::destruct_scaling_layer(void)
{
   delete scaling_layer_pointer;

   scaling_layer_pointer = NULL;
}


// void destruct_unscaling_layer(void) method

/// This method deletes the unscaling layer within the neural network. 

void NeuralNetwork::destruct_unscaling_layer(void)
{
   delete unscaling_layer_pointer;

   unscaling_layer_pointer = NULL;
}


// void destruct_bounding_layer(void) method

/// This method deletes the bounding layer within the neural network. 

void NeuralNetwork::destruct_bounding_layer(void)
{
   delete bounding_layer_pointer;

   bounding_layer_pointer = NULL;
}


// void destruct_probabilistic_layer(void) method

/// This method deletes the probabilistic layer within the neural network. 

void NeuralNetwork::destruct_probabilistic_layer(void)
{
   delete probabilistic_layer_pointer;

   probabilistic_layer_pointer = NULL;
}


// void destruct_conditions_layer(void) method

/// This method deletes the conditions layer within the neural network. 

void NeuralNetwork::destruct_conditions_layer(void)
{
   delete conditions_layer_pointer;

   conditions_layer_pointer = NULL;
}


// void destruct_inputs(void) method

/// This method deletes the inputs object within the neural network.

void NeuralNetwork::destruct_inputs(void)
{
   delete inputs_pointer;

   inputs_pointer = NULL;
}


// void destruct_outputs(void) method

/// This method deletes the outputs object within the neural network.

void NeuralNetwork::destruct_outputs(void)
{
   delete outputs_pointer;

   outputs_pointer = NULL;
}


// void destruct_independent_parameters(void) method

/// This method deletes the independent parameters object within the neural network. 

void NeuralNetwork::destruct_independent_parameters(void)
{
   delete independent_parameters_pointer;

   independent_parameters_pointer = NULL;
}


// void initialize_random(void) method

/// Initializes the neural network at random.
/// This is useful for testing purposes. 

void NeuralNetwork::initialize_random(void)
{
   unsigned inputs_number;
   unsigned outputs_number;

   // Multilayer perceptron

   if(rand()%5)
   {
      if(!multilayer_perceptron_pointer)
      {
         multilayer_perceptron_pointer = new MultilayerPerceptron();
      }

      multilayer_perceptron_pointer->initialize_random();

      inputs_number = multilayer_perceptron_pointer->get_inputs_number();
      outputs_number = multilayer_perceptron_pointer->get_outputs_number();
   }
   else
   {
      inputs_number =  rand()%10 + 1;
      outputs_number =  rand()%10 + 1;   
   }

   // Scaling layer

   if(rand()%5)
   {
      if(!scaling_layer_pointer)
      {
         scaling_layer_pointer = new ScalingLayer(inputs_number);
      }

      scaling_layer_pointer->initialize_random();
   }

   // Unscaling layer

   if(rand()%5)
   {
      if(!unscaling_layer_pointer)
      {
         unscaling_layer_pointer = new UnscalingLayer(outputs_number);
      }

      unscaling_layer_pointer->initialize_random();
   }

   // Bounding layer 

   if(rand()%5)
   {
      if(!bounding_layer_pointer)
      {
         bounding_layer_pointer = new BoundingLayer(outputs_number);
      }

      bounding_layer_pointer->initialize_random();
   }

   // Probabilistic layer

   if(rand()%5)
   {
      if(!probabilistic_layer_pointer)
      {
         probabilistic_layer_pointer = new ProbabilisticLayer(outputs_number);
      }

      probabilistic_layer_pointer->initialize_random();
   }

   // Conditions layer

   if(rand()%5)
   {
      if(!conditions_layer_pointer)
      {
         conditions_layer_pointer = new ConditionsLayer(inputs_number, outputs_number);
      }

      conditions_layer_pointer->initialize_random();
   }

   // Inputs

   if(rand()%5)
   {
      if(!inputs_pointer)
      {
         inputs_pointer = new Inputs(inputs_number);
      }
   }

   // Outputs

   if(rand()%5)
   {
      if(!outputs_pointer)
      {
         outputs_pointer = new Outputs(outputs_number);
      }
   }

   // Independent parameters 

   if(rand()%5)
   {
      if(!independent_parameters_pointer)
      {
         independent_parameters_pointer = new IndependentParameters();
      }

      independent_parameters_pointer->initialize_random();
   }
}


// void set_display(const bool&) method

/// Sets a new display value.
/// If it is set to true messages from this class are to be displayed on the screen;
/// if it is set to false messages from this class are not to be displayed on the screen.
/// @param new_display Display value.

void NeuralNetwork::set_display(const bool& new_display)
{
   display = new_display;
}


// void prune_input(const unsigned&) method

/// Removes a given input to the neural network.
/// This involves removing the input itself and the corresponding scaling layer,
/// conditions layer and multilayer perceptron inputs.
/// @param index Index of input to be pruned.

void NeuralNetwork::prune_input(const unsigned& index)
{
    if(!multilayer_perceptron_pointer)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: NeuralNetwork class.\n"
               << "void prune_input(const unsigned&) method.\n"
               << "Pointer to multilayer perceptron is NULL.\n";

      throw std::logic_error(buffer.str());
    }

    multilayer_perceptron_pointer->prune_input(index);

    if(scaling_layer_pointer)
    {
        scaling_layer_pointer->prune_scaling_neuron(index);
    }

    if(conditions_layer_pointer)
    {
    }

    if(inputs_pointer)
    {
        inputs_pointer->prune_input(index);
    }
}


// void prune_output(const unsigned&) method

/// Removes a given output from the neural network.
/// This involves removing the output itself and the corresponding unscaling layer,
/// conditions layer, probabilistic layer, bounding layer and multilayer perceptron outputs.
/// @param index Index of output to be pruned.

void NeuralNetwork::prune_output(const unsigned& index)
{
    if(!multilayer_perceptron_pointer)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: NeuralNetwork class.\n"
               << "void prune_output(const unsigned&) method.\n"
               << "Pointer to multilayer perceptron is NULL.\n";

      throw std::logic_error(buffer.str());
    }

    multilayer_perceptron_pointer->prune_output(index);

    if(unscaling_layer_pointer)
    {
        unscaling_layer_pointer->prune_unscaling_neuron(index);
    }

    if(bounding_layer_pointer)
    {
        bounding_layer_pointer->prune_bounding_neuron(index);
    }

    if(probabilistic_layer_pointer)
    {
        probabilistic_layer_pointer->prune_probabilistic_neuron();
    }

    if(conditions_layer_pointer)
    {
    }

    if(outputs_pointer)
    {
        outputs_pointer->prune_output(index);
    }
}


// void resize_inputs_number(const unsigned&) method

/// @todo

void NeuralNetwork::resize_inputs_number(const unsigned&)
{

}


// void resize_outputs_number(const unsigned&) method

/// @todo

void NeuralNetwork::resize_outputs_number(const unsigned&)
{

}


// unsigned get_layers_number(void) method

/// Returns the number of layers in the neural network.
/// That includes perceptron, scaling, unscaling, bounding, probabilistic or conditions layers. 

unsigned NeuralNetwork::get_layers_number(void)
{
   unsigned layers_number = 0; 

   if(multilayer_perceptron_pointer)
   {
      layers_number += multilayer_perceptron_pointer->get_layers_number();
   }

   if(scaling_layer_pointer)
   {
      layers_number += 1;   
   }

   if(unscaling_layer_pointer)
   {
      layers_number += 1;   
   }

   if(bounding_layer_pointer)
   {
      layers_number += 1;   
   }

   if(probabilistic_layer_pointer)
   {
      layers_number += 1;   
   }

   if(conditions_layer_pointer)
   {
      layers_number += 1;   
   }

   return(layers_number);
}


// void initialize_parameters(const double&) method

/// Initializes all the neural and the independent parameters with a given value.

void NeuralNetwork::initialize_parameters(const double& value)
{
   if(multilayer_perceptron_pointer)
   {
      multilayer_perceptron_pointer->initialize_parameters(value);
   }

   if(independent_parameters_pointer)
   {
      independent_parameters_pointer->initialize_parameters(value);
   }
}


// void randomize_parameters_uniform(void) method

/// Initializes all the parameters in the newtork (biases and synaptic weiths + independent parameters)
/// at random with values comprised between -1 and +1.

void NeuralNetwork::randomize_parameters_uniform(void)
{
   if(multilayer_perceptron_pointer)
   {
      multilayer_perceptron_pointer->randomize_parameters_uniform();  
   }

   if(independent_parameters_pointer)
   {
      independent_parameters_pointer->randomize_parameters_uniform();  
   }
}


// void randomize_parameters_uniform(const double&, const double&) method

/// Initializes all the parameters in the newtork (biases and synaptic weiths + independent
/// parameters) at random with values comprised between a given minimum and a given maximum values.
/// @param minimum Minimum initialization value.
/// @param maximum Maximum initialization value.

void NeuralNetwork::randomize_parameters_uniform(const double& minimum, const double& maximum)
{
   if(multilayer_perceptron_pointer)
   {
      multilayer_perceptron_pointer->randomize_parameters_uniform(minimum, maximum);  
   }

   if(independent_parameters_pointer)
   {
      independent_parameters_pointer->randomize_parameters_uniform(minimum, maximum);  
   }
}


// void randomize_parameters_uniform(const Vector<double>&, const Vector<double>&) method

/// Initializes all the parameters in the newtork (biases and synaptic weiths + independent
/// parameters) at random with values comprised between a different minimum and maximum numbers for each free 
/// parameter.
/// @param minimum Vector of minimum initialization values.
/// @param maximum Vector of maximum initialization values.

void NeuralNetwork::randomize_parameters_uniform(const Vector<double>& minimum, const Vector<double>& maximum)
{
   if(multilayer_perceptron_pointer)
   {
      multilayer_perceptron_pointer->randomize_parameters_uniform(minimum, maximum);  
   }

   if(independent_parameters_pointer)
   {
      independent_parameters_pointer->randomize_parameters_uniform(minimum, maximum);  
   }
}


// void randomize_parameters_uniform(const Vector< Vector<double> >&) method

/// Initializes all the parameters in the newtork (biases and synaptic weiths + independent
/// parameters) values comprised between a different minimum and maximum numbers for each parameter.
/// Minimum and maximum initialization values are given from a vector of two real vectors.
/// The first element must contain the minimum initialization value for each parameter.
/// The second element must contain the maximum initialization value for each parameter.
/// @param minimum_maximum Vector of minimum and maximum initialization vectors.

void NeuralNetwork::randomize_parameters_uniform(const Vector< Vector<double> >& minimum_maximum)
{
   if(multilayer_perceptron_pointer)
   {
      multilayer_perceptron_pointer->randomize_parameters_uniform(minimum_maximum);  
   }

   if(independent_parameters_pointer)
   {
      independent_parameters_pointer->randomize_parameters_uniform(minimum_maximum); 
   }
}


// void randomize_parameters_normal(void) method

/// Initializes all the parameters in the neural newtork (biases and synaptic weiths + independent
/// parameters) at random with values chosen from a normal distribution with mean 0 and standard deviation 1.

void NeuralNetwork::randomize_parameters_normal(void)
{
   if(multilayer_perceptron_pointer)
   {
      multilayer_perceptron_pointer->randomize_parameters_normal();  
   }

   if(independent_parameters_pointer)
   {
      independent_parameters_pointer->randomize_parameters_normal(); 
   }
}


// void randomize_parameters_normal(const double&, const double&) method

/// Initializes all the parameters in the newtork (biases and synaptic weiths + independent
/// parameters) at random with values chosen from a normal distribution with a given mean and a given standard 
/// deviation.
/// @param mean Mean of normal distribution.
/// @param standard_deviation Standard deviation of normal distribution.

void NeuralNetwork::randomize_parameters_normal(const double& mean, const double& standard_deviation)
{
   if(multilayer_perceptron_pointer)
   {
      multilayer_perceptron_pointer->randomize_parameters_normal(mean, standard_deviation);  
   }

   if(independent_parameters_pointer)
   {
      independent_parameters_pointer->randomize_parameters_normal(mean, standard_deviation); 
   }
}


// void randomize_parameters_normal(const Vector<double>&, const Vector<double>&) method

/// Initializes all the parameters in the neural newtork (biases and synaptic weiths +
/// independent parameters) at random with values chosen from normal distributions with a given mean and a given 
/// standard deviation for each parameter.
/// @param mean Vector of minimum initialization values.
/// @param standard_deviation Vector of maximum initialization values.

void NeuralNetwork::randomize_parameters_normal(const Vector<double>& mean, const Vector<double>& standard_deviation)
{
   if(multilayer_perceptron_pointer)
   {
      multilayer_perceptron_pointer->randomize_parameters_normal(mean, standard_deviation);  
   }

   if(independent_parameters_pointer)
   {
      independent_parameters_pointer->randomize_parameters_normal(mean, standard_deviation);  
   }
}


// void randomize_parameters_normal(const Vector< Vector<double> >&) method

/// Initializes all the parameters in the newtork (biases and synaptic weiths + independent
/// parameters) at random with values chosen from normal distributions with a given mean and a given standard 
/// deviation for each parameter.
/// All mean and standard deviation values are given from a vector of two real vectors.
/// The first element must contain the mean value for each parameter.
/// The second element must contain the standard deviation value for each parameter.
/// @param mean_standard_deviation Mean and standard deviation vectors.

void NeuralNetwork::randomize_parameters_normal(const Vector< Vector<double> >& mean_standard_deviation)
{
   if(multilayer_perceptron_pointer)
   {
      multilayer_perceptron_pointer->randomize_parameters_normal(mean_standard_deviation);  
   }

   if(independent_parameters_pointer)
   {
      independent_parameters_pointer->randomize_parameters_normal(mean_standard_deviation);  
   }
}


// double calculate_parameters_norm(void) const method

/// Returns the norm of the vector of parameters.

double NeuralNetwork::calculate_parameters_norm(void) const
{
   const Vector<double> parameters = arrange_parameters();

   const double parameters_norm = parameters.calculate_norm();

   return(parameters_norm);
}


// Statistics<double> calculate_parameters_statistics(void) const method

/// Returns a statistics structure of the parameters vector.
/// That contains the minimum, maximum, mean and standard deviation values of the parameters.

Statistics<double> NeuralNetwork::calculate_parameters_statistics(void) const
{
    const Vector<double> parameters = arrange_parameters();

    return(parameters.calculate_statistics());
}


// Histogram calculate_parameters_histogram(const unsigned& = 10) const method

/// Returns a histogram structure of the parameters vector.
/// That will be used for looking at the distribution of the parameters.
/// @param bins_number Number of bins in the histogram (10 by default).

Histogram<double> NeuralNetwork::calculate_parameters_histogram(const unsigned& bins_number) const
{
    const Vector<double> parameters = arrange_parameters();

    return(parameters.calculate_histogram(bins_number));
}


// Vector<double> calculate_outputs(const Vector<double>&) method method

/// Calculates the outputs vector from the multilayer perceptron in response to an inputs vector.
/// The activity for that is the following:
/// <ul>
/// <li> Check inputs range.
/// <li> Calculate scaled inputs.
/// <li> Calculate forward propagation.
/// <li> Calculate unscaled outputs.
/// <li> Apply boundary condtions.
/// <li> Calculate bounded outputs. 
/// </ul>
/// @param inputs Set of inputs to the neural network.

Vector<double> NeuralNetwork::calculate_outputs(const Vector<double>& inputs) const																
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   if(multilayer_perceptron_pointer)
   {
      const unsigned inputs_size = inputs.size();

      const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();

      if(inputs_size != inputs_number) 
      {
         std::ostringstream buffer;

         buffer << "OpenNN Exception: NeuralNetwork class.\n"
                << "Vector<double> calculate_outputs(const Vector<double>&) const method.\n"
                << "Size of inputs must be equal to number of inputs.\n";

	   throw std::logic_error(buffer.str());
      }
   }
   
   #endif

   Vector<double> outputs(inputs);

   // Scaling layer

   if(scaling_layer_pointer)
   {
      outputs = scaling_layer_pointer->calculate_outputs(inputs);
   }

   // Multilayer perceptron

   if(multilayer_perceptron_pointer)
   {
      outputs = multilayer_perceptron_pointer->calculate_outputs(outputs);
   }

   // Conditions

   if(conditions_layer_pointer)
   {
      outputs = conditions_layer_pointer->calculate_outputs(inputs, outputs);
   }

   // Unscaling layer

   if(unscaling_layer_pointer)
   {
      outputs = unscaling_layer_pointer->calculate_outputs(outputs);
   }

   // Probabilistic layer

   if(probabilistic_layer_pointer)
   {
      outputs = probabilistic_layer_pointer->calculate_outputs(outputs);   
   }

   // Bounding layer

   if(bounding_layer_pointer)
   {
      outputs = bounding_layer_pointer->calculate_outputs(outputs);
   }

   return(outputs);
}


// Matrix<double> calculate_directional_input_data(const unsigned&, const Vector<double>&, const double&, const double&, const unsigned& = 101) const

/// Calculates the input data which is necessary to compute the output data from the neural network in some direction.
/// @param direction Input index (must be between 0 and number of inputs - 1).
/// @param point Input point through the directional input passes.
/// @param minimum Minimum value of the input with the above index.
/// @param maximum Maximum value of the input with the above index.
/// @param points_number Number of points in the directional input data set.

Matrix<double> NeuralNetwork::calculate_directional_input_data(const unsigned& direction,
                                                               const Vector<double>& point,
                                                               const double& minimum,
                                                               const double& maximum,
                                                               const unsigned& points_number) const
{
    const unsigned inputs_number = inputs_pointer->get_inputs_number();

    Matrix<double> directional_input_data(points_number, inputs_number);

    Vector<double> inputs(inputs_number);

    inputs = point;

    for(unsigned i = 0; i < points_number; i++)
    {
        inputs[direction] = minimum + (maximum-minimum)*i/(double)(points_number-1);

        directional_input_data.set_row(i, inputs);
    }

    return(directional_input_data);
}


// Vector<double> calculate_outputs(const Vector<double>&, const Vector<double>&) const method

/// Returns which would be the outputs for a given inputs and a set of parameters.
/// @param inputs Vector of inputs to the neural network.
/// @param parameters Vector of potential parameters of the neural network.

Vector<double> NeuralNetwork::calculate_outputs(const Vector<double>& inputs, const Vector<double>& parameters) const
{
   // Control sentence (if debug)

   #ifndef NDEBUG 

   const unsigned inputs_size = inputs.size();

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();

   if(inputs_size != inputs_number)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "Vector<double> calculate_outputs(const Vector<double>&, const Vector<double>&) const method.\n"
             << "Size of inputs (" << inputs_size << ") must be equal to number of inputs (" << inputs_number << ").\n";

	  throw std::logic_error(buffer.str());
   }

   const unsigned parameters_size = parameters.size();

   const unsigned parameters_number = count_parameters_number();

   if(parameters_size != parameters_number)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "Vector<double> calculate_outputs(const Vector<double>&, const Vector<double>&) const method.\n"
             << "Size of potential parameters (" << parameters_size << ") must be equal to number of parameters (" << parameters_number << ").\n";

	  throw std::logic_error(buffer.str());
   }

   #endif

   Vector<double> outputs(inputs);

   // Scaling layer

   if(scaling_layer_pointer)
   {
      outputs = scaling_layer_pointer->calculate_outputs(inputs);
   }

   // Multilayer perceptron

   if(multilayer_perceptron_pointer)
   {
      outputs = multilayer_perceptron_pointer->calculate_outputs(outputs, parameters);
   }

   // Conditions

   if(conditions_layer_pointer)
   {
      outputs = conditions_layer_pointer->calculate_outputs(inputs, outputs);
   }

   // Unscaling layer

   if(unscaling_layer_pointer)
   {
      outputs = unscaling_layer_pointer->calculate_outputs(outputs);
   }

   // Probabilistic layer

   if(probabilistic_layer_pointer)
   {
      outputs = probabilistic_layer_pointer->calculate_outputs(outputs);
   }

   // Bounding layer

   if(bounding_layer_pointer)
   {
      outputs = bounding_layer_pointer->calculate_outputs(outputs);
   }

   return(outputs);
}


// Matrix<double> calculate_output_data(const Matrix<double>&) const method

/// Calculates a set of outputs from the neural network in response to a set of inputs.
/// The format is a matrix, where each row contains the output for a single input.
/// @param input_data Matrix of inputs to the neural network. 

Matrix<double> NeuralNetwork::calculate_output_data(const Matrix<double>& input_data) const
{
   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   // Control sentence (if debug)

   #ifndef NDEBUG 

   const unsigned columns_number = input_data.get_columns_number();

   if(columns_number != inputs_number) 
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "Matrix<double> calculate_output_data(const Matrix<double>&) const method.\n"
             << "Number of columns must be equal to number of inputs.\n";

	  throw std::logic_error(buffer.str());
   }   

   #endif
  
   const unsigned input_vectors_number = input_data.get_rows_number();

   Matrix<double> output_data(input_vectors_number, outputs_number);

   Vector<double> inputs(inputs_number);
   Vector<double> outputs(outputs_number);

   for(unsigned i = 0; i < input_vectors_number; i++)
   {
      inputs = input_data.arrange_row(i);
      outputs = calculate_outputs(inputs);
      output_data.set_row(i, outputs);
   }

   return(output_data);
}


// Matrix<double> calculate_Jacobian(const Vector<double>&) const method

/// Returns the Jacobian Matrix of the neural network for a set of inputs, corresponding to the
/// point in inputs space at which the Jacobian Matrix is to be found. It uses a forward-propagation method.
/// @param inputs Set of inputs to the neural network.
/// @todo

Matrix<double> NeuralNetwork::calculate_Jacobian(const Vector<double>& inputs) const
{
   #ifndef NDEBUG 

   const unsigned size = inputs.size();

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();

   if(size != inputs_number)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "void calculate_Jacobian(const Vector<double>&) const method.\n"
             << "Size must be equal to number of inputs.\n";

	  throw std::logic_error(buffer.str());
   }

   #endif

   Vector<double> outputs(inputs);

   Matrix<double> scaling_layer_Jacobian;
   Matrix<double> unscaling_layer_Jacobian;
   Matrix<double> multilayer_perceptron_Jacobian;
   Matrix<double> bounding_layer_Jacobian;
   Matrix<double> conditions_layer_Jacobian;
   Matrix<double> probabilistic_layer_Jacobian;

   // Scaling layer

   if(scaling_layer_pointer)
   {
      const Vector<double> scaling_layer_derivative = scaling_layer_pointer->calculate_derivatives(outputs);
      scaling_layer_Jacobian = scaling_layer_pointer->arrange_Jacobian(scaling_layer_derivative);

      outputs = scaling_layer_pointer->calculate_outputs(outputs);
   }

   // Multilayer perceptron

   if(multilayer_perceptron_pointer)
   {
      multilayer_perceptron_Jacobian = multilayer_perceptron_pointer->calculate_Jacobian(outputs);

      outputs = multilayer_perceptron_pointer->calculate_outputs(outputs);
   }

   // Unscaling layer
   
   if(unscaling_layer_pointer)
   {
      const Vector<double> unscaling_layer_derivative = unscaling_layer_pointer->calculate_derivatives(outputs);
      unscaling_layer_Jacobian = unscaling_layer_pointer->arrange_Jacobian(unscaling_layer_derivative);

      outputs = unscaling_layer_pointer->calculate_outputs(outputs);
   }

   // Probabilistic layer

   if(probabilistic_layer_pointer)
   {
      probabilistic_layer_Jacobian = probabilistic_layer_pointer->calculate_Jacobian(outputs);

      outputs = probabilistic_layer_pointer->calculate_outputs(outputs);
   }

   // Bounding layer

   if(bounding_layer_pointer)
   {
      const Vector<double>& derivatives = bounding_layer_pointer->calculate_derivative(outputs);

      bounding_layer_Jacobian = bounding_layer_pointer->arrange_Jacobian(derivatives);

      outputs = bounding_layer_pointer->calculate_outputs(outputs);
   }

   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   Matrix<double> Jacobian(outputs_number, outputs_number, 0.0);
   Jacobian.set_diagonal(1.0);

   // Bounding layer

   if(bounding_layer_pointer)
   {
      Jacobian = Jacobian.dot(bounding_layer_Jacobian);
   }

   // Probabilistic outputs

   if(probabilistic_layer_pointer)
   {
      Jacobian = Jacobian.dot(probabilistic_layer_Jacobian);
   }

   // Unscaling layer

   if(unscaling_layer_pointer)
   {
      Jacobian = Jacobian.dot(unscaling_layer_Jacobian);
   }

   // Multilayer perceptron

   if(multilayer_perceptron_pointer)
   {
      Jacobian = Jacobian.dot(multilayer_perceptron_Jacobian);
   }

   // Scaling layer

   if(scaling_layer_pointer)
   {
      Jacobian = Jacobian.dot(scaling_layer_Jacobian);
   }

   // Conditions 

   if(conditions_layer_pointer)
   {
      conditions_layer_Jacobian = conditions_layer_pointer->calculate_Jacobian(inputs, outputs, Jacobian);

      outputs = conditions_layer_pointer->calculate_outputs(inputs, outputs);
   }

   if(conditions_layer_pointer)
   {
      Jacobian = Jacobian.dot(conditions_layer_Jacobian);
   }

   return(Jacobian);
}


// Vector< Matrix<double> > calculate_Jacobian_data(const Matrix<double>&) const method

/// Calculates a set of Jacobians from the neural network in response to a set of inputs.
/// The format is a vector of matrices, where each element is the Jacobian matrix for a single input.
/// @param input_data Matrix of inputs to the neural network.

Vector< Matrix<double> > NeuralNetwork::calculate_Jacobian_data(const Matrix<double>& input_data) const
{
    const unsigned inputs_number = inputs_pointer->get_inputs_number();

    const unsigned input_data_size = input_data.get_rows_number();

    Vector< Matrix<double> > Jacobian_data(input_data_size);

    Vector<double> input_values(inputs_number);

    for(unsigned i = 0; i < input_data_size; i++)
    {
        input_values = input_data.arrange_row(i);

        Jacobian_data[i] = calculate_Jacobian(input_values);
    }

    return(Jacobian_data);
}


// Matrix<double> calculate_Jacobian(const Vector<double>&, const Vector<double>&) const method

/// Returns the partial derivatives of the outputs with respect to a given set of parameters.
/// @todo

Matrix<double> NeuralNetwork::calculate_Jacobian(const Vector<double>& inputs, const Vector<double>& parameters) const
{
   return(multilayer_perceptron_pointer->calculate_Jacobian(inputs, parameters));
}


// Vector< Matrix<double> > calculate_Hessian_form(const Vector<double>&) const method

/// Returns the second partial derivatives of the outputs with respect to the inputs.
/// @todo

Vector< Matrix<double> > NeuralNetwork::calculate_Hessian_form(const Vector<double>& inputs) const
{
   return(multilayer_perceptron_pointer->calculate_Hessian_form(inputs));
}


// Vector< Matrix<double> > calculate_Hessian_form(const Vector<double>&, const Vector<double>&) const method

/// Returns the second partial derivatives of the outputs with respect to the neural network parameters.
/// @todo

Vector< Matrix<double> > NeuralNetwork::calculate_Hessian_form(const Vector<double>& inputs, const Vector<double>& parameters) const
{
   return(multilayer_perceptron_pointer->calculate_Hessian_form(inputs, parameters));
}


// std::string to_string(void) const method

/// Returns a string representation of the current neural network object.

std::string NeuralNetwork::to_string(void) const
{
   std::ostringstream buffer;

   buffer << "NeuralNetwork\n";

   // Multilayer perceptron 

   if(multilayer_perceptron_pointer)
   {
      buffer << multilayer_perceptron_pointer->to_string();
   }
 
   // Scaling layer

   if(scaling_layer_pointer)
   {
      buffer << scaling_layer_pointer->to_string();
   }

   // Unscaling layer

   if(unscaling_layer_pointer)
   {
      buffer << unscaling_layer_pointer->to_string();
   }

   // Bounding layer

   if(bounding_layer_pointer)
   {
      buffer << bounding_layer_pointer->to_string();
   }

   // Probabilistic layer

   if(probabilistic_layer_pointer)
   {
      buffer << probabilistic_layer_pointer->to_string();
   }

   // Conditions layer

   if(conditions_layer_pointer)
   {
      buffer << conditions_layer_pointer->to_string();
   }

   // Inputs

   if(inputs_pointer)
   {
      buffer << inputs_pointer->to_string();
   }

   // Outputs

   if(outputs_pointer)
   {
      buffer << outputs_pointer->to_string();
   }

   // Independent parameters

   if(independent_parameters_pointer)
   {
      buffer << independent_parameters_pointer->to_string();
   }

   buffer << "Display: " <<  display << "\n";

   return(buffer.str());
}


// tinyxml2::XMLDocument* to_XML(void) const method

/// Serializes the neural network object into a XML document of the TinyXML library.
/// See the OpenNN manual for more information about the format of this element. 

tinyxml2::XMLDocument* NeuralNetwork::to_XML(void) const
{
   tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument;

   tinyxml2::XMLElement* neural_network_element = document->NewElement("NeuralNetwork");

   document->InsertFirstChild(neural_network_element);

   std::ostringstream buffer;

   // Inputs

   if(inputs_pointer)
   {
      tinyxml2::XMLElement* element = document->NewElement("Inputs");
      neural_network_element->LinkEndChild(element);    

      const tinyxml2::XMLDocument* inputs_document = inputs_pointer->to_XML();

      const tinyxml2::XMLElement* inputsElement = inputs_document->FirstChildElement("Inputs");

      DeepClone(element, inputsElement, document, NULL);

      delete inputs_document;
   }

   // Scaling layer

   if(scaling_layer_pointer)
   {
       tinyxml2::XMLElement* element = document->NewElement("ScalingLayer");
       neural_network_element->LinkEndChild(element);

       const tinyxml2::XMLDocument* scaling_layer_document = scaling_layer_pointer->to_XML();

       const tinyxml2::XMLElement* scaling_layer_element = scaling_layer_document->FirstChildElement("ScalingLayer");

       DeepClone(element, scaling_layer_element, document, NULL);

       delete scaling_layer_document;
   }

   // Multilayer perceptron 

   if(multilayer_perceptron_pointer)
   {
       tinyxml2::XMLElement* element = document->NewElement("MultilayerPerceptron");
       neural_network_element->LinkEndChild(element);

       const tinyxml2::XMLDocument* multilayer_perceptron_document = multilayer_perceptron_pointer->to_XML();

       const tinyxml2::XMLElement* multilayer_perceptron_element = multilayer_perceptron_document->FirstChildElement("MultilayerPerceptron");

       DeepClone(element, multilayer_perceptron_element, document, NULL);

       delete multilayer_perceptron_document;
   }

   // Unscaling layer

   if(unscaling_layer_pointer)
   {
       tinyxml2::XMLElement* element = document->NewElement("UnscalingLayer");
       neural_network_element->LinkEndChild(element);

       const tinyxml2::XMLDocument* unscaling_layer_document = unscaling_layer_pointer->to_XML();

       const tinyxml2::XMLElement* unscaling_layer_element = unscaling_layer_document->FirstChildElement("UnscalingLayer");

       DeepClone(element, unscaling_layer_element, document, NULL);

       delete unscaling_layer_document;
   }

   // Probabilistic layer

   if(probabilistic_layer_pointer)
   {
       tinyxml2::XMLElement* element = document->NewElement("ProbabilisticLayer");
       neural_network_element->LinkEndChild(element);

       const tinyxml2::XMLDocument* probabilistic_layer_document = probabilistic_layer_pointer->to_XML();

       const tinyxml2::XMLElement* probabilistic_layer_element = probabilistic_layer_document->FirstChildElement("ProbabilisticLayer");

       DeepClone(element, probabilistic_layer_element, document, NULL);

       delete probabilistic_layer_document;
   }

   // Bounding layer

   if(bounding_layer_pointer)
   {
       tinyxml2::XMLElement* element = document->NewElement("BoundingLayer");
       neural_network_element->LinkEndChild(element);

       const tinyxml2::XMLDocument* bounding_layer_document = bounding_layer_pointer->to_XML();

       const tinyxml2::XMLElement* bounding_layer_element = bounding_layer_document->FirstChildElement("BoundingLayer");

       DeepClone(element, bounding_layer_element, document, NULL);

       delete bounding_layer_document;
   }

   // Conditions layer

   if(conditions_layer_pointer)
   {
       tinyxml2::XMLElement* element = document->NewElement("ConditionsLayer");
       neural_network_element->LinkEndChild(element);

       const tinyxml2::XMLDocument* conditions_layer_document = conditions_layer_pointer->to_XML();

       const tinyxml2::XMLElement* conditions_layer_element = conditions_layer_document->FirstChildElement("ConditionsLayer");

       DeepClone(element, conditions_layer_element, document, NULL);

       delete conditions_layer_document;
   }

   // Outputs

   if(outputs_pointer)
   {
       tinyxml2::XMLElement* element = document->NewElement("Outputs");
       neural_network_element->LinkEndChild(element);

       const tinyxml2::XMLDocument* outputs_document = outputs_pointer->to_XML();

       const tinyxml2::XMLElement* outputs_element = outputs_document->FirstChildElement("Outputs");

       DeepClone(element, outputs_element, document, NULL);

       delete outputs_document;
   }

   // Independent parameters

   if(independent_parameters_pointer)
   {
       tinyxml2::XMLElement* element = document->NewElement("IndependentParameters");
       neural_network_element->LinkEndChild(element);

       const tinyxml2::XMLDocument* independent_parameters_document = independent_parameters_pointer->to_XML();

       const tinyxml2::XMLElement* independent_parameters_element = independent_parameters_document->FirstChildElement("IndependentParameters");

       DeepClone(element, independent_parameters_element, document, NULL);

       delete independent_parameters_document;
   }

   // Display warnings
   {
      tinyxml2::XMLElement* display_element = document->NewElement("Display");
      neural_network_element->LinkEndChild(display_element);

      buffer.str("");
      buffer << display;

      tinyxml2::XMLText* display_text = document->NewText(buffer.str().c_str());
      display_element->LinkEndChild(display_text);
   }

   return(document);
}


// void from_XML(const tinyxml2::XMLDocument&) method

/// Deserializes a TinyXML document into this neural network object.
/// @param document XML document containing the member data.

void NeuralNetwork::from_XML(const tinyxml2::XMLDocument& document)
{
   std::ostringstream buffer;

   const tinyxml2::XMLElement* root_element = document.FirstChildElement("NeuralNetwork");

   if(!root_element)
   {
       buffer << "OpenNN Exception: NeuralNetwork class.\n"
              << "void from_XML(const tinyxml2::XMLDocument&) method.\n"
              << "Neural network element is NULL.\n";

       throw std::logic_error(buffer.str());
   }

   // Inputs
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("Inputs");

       if(element)
       {
          if(!inputs_pointer)
          {
             inputs_pointer = new Inputs();
          }

          tinyxml2::XMLDocument inputs_document;

          tinyxml2::XMLElement* element_clone = inputs_document.NewElement("Inputs");
          inputs_document.InsertFirstChild(element_clone);

          DeepClone(element_clone, element, &inputs_document, NULL);

          inputs_pointer->from_XML(inputs_document);
       }
   }

   // Outputs
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("Outputs");

       if(element)
       {
          if(!outputs_pointer)
          {
             outputs_pointer = new Outputs();
          }

          tinyxml2::XMLDocument outputs_document;

          tinyxml2::XMLElement* element_clone = outputs_document.NewElement("Outputs");
          outputs_document.InsertFirstChild(element_clone);

          DeepClone(element_clone, element, &outputs_document, NULL);

          outputs_pointer->from_XML(outputs_document);
       }
   }

   // Multilayer perceptron
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("MultilayerPerceptron");

       if(element)
       {
          if(!multilayer_perceptron_pointer)
          {
             multilayer_perceptron_pointer = new MultilayerPerceptron();
          }

          tinyxml2::XMLDocument multilayer_perceptron_document;

          tinyxml2::XMLElement* element_clone = multilayer_perceptron_document.NewElement("MultilayerPerceptron");
          multilayer_perceptron_document.InsertFirstChild(element_clone);

          DeepClone(element_clone, element, &multilayer_perceptron_document, NULL);

          multilayer_perceptron_pointer->from_XML(multilayer_perceptron_document);
       }
   }

   // Scaling layer
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ScalingLayer");

       if(element)
       {
          if(!scaling_layer_pointer)
          {
             scaling_layer_pointer = new ScalingLayer();
          }

          tinyxml2::XMLDocument scaling_layer_document;

          tinyxml2::XMLElement* element_clone = scaling_layer_document.NewElement("ScalingLayer");
          scaling_layer_document.InsertFirstChild(element_clone);

          DeepClone(element_clone, element, &scaling_layer_document, NULL);

          scaling_layer_pointer->from_XML(scaling_layer_document);
       }
   }

   // Unscaling layer
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("UnscalingLayer");

       if(element)
       {
          if(!unscaling_layer_pointer)
          {
             unscaling_layer_pointer = new UnscalingLayer();
          }

          tinyxml2::XMLDocument unscaling_layer_document;

          tinyxml2::XMLElement* element_clone = unscaling_layer_document.NewElement("UnscalingLayer");
          unscaling_layer_document.InsertFirstChild(element_clone);

          DeepClone(element_clone, element, &unscaling_layer_document, NULL);

          unscaling_layer_pointer->from_XML(unscaling_layer_document);
       }
   }

   // Bounding layer
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("BoundingLayer");

       if(element)
       {
          if(!bounding_layer_pointer)
          {
             bounding_layer_pointer = new BoundingLayer();
          }

          tinyxml2::XMLDocument bounding_layer_document;

          tinyxml2::XMLElement* element_clone = bounding_layer_document.NewElement("BoundingLayer");
          bounding_layer_document.InsertFirstChild(element_clone);

          DeepClone(element_clone, element, &bounding_layer_document, NULL);

          bounding_layer_pointer->from_XML(bounding_layer_document);
       }
   }

   // Probabilistic layer 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ProbabilisticLayer");

       if(element)
       {
          if(!probabilistic_layer_pointer)
          {
             probabilistic_layer_pointer = new ProbabilisticLayer();
          }

          tinyxml2::XMLDocument probabilistic_layer_document;

          tinyxml2::XMLElement* element_clone = probabilistic_layer_document.NewElement("ProbabilisticLayer");
          probabilistic_layer_document.InsertFirstChild(element_clone);

          DeepClone(element_clone, element, &probabilistic_layer_document, NULL);

          probabilistic_layer_pointer->from_XML(probabilistic_layer_document);
       }
   }

   // Conditions layer 
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("ConditionsLayer");

       if(element)
       {
          if(!conditions_layer_pointer)
          {
             conditions_layer_pointer = new ConditionsLayer();
          }

          tinyxml2::XMLDocument conditions_layer_document;

          tinyxml2::XMLElement* element_clone = conditions_layer_document.NewElement("ConditionsLayer");
          conditions_layer_document.InsertFirstChild(element_clone);

          DeepClone(element_clone, element, &conditions_layer_document, NULL);

          conditions_layer_pointer->from_XML(conditions_layer_document);
       }
   }

   // Indpependent parameters
   {
       const tinyxml2::XMLElement* element = root_element->FirstChildElement("IndependentParameters");

       if(element)
       {
          if(!independent_parameters_pointer)
          {
             independent_parameters_pointer = new IndependentParameters();
          }

          tinyxml2::XMLDocument independent_parameters_document;

          tinyxml2::XMLElement* element_clone = independent_parameters_document.NewElement("IndependentParameters");
          independent_parameters_document.InsertFirstChild(element_clone);

          DeepClone(element_clone, element, &independent_parameters_document, NULL);

          independent_parameters_pointer->from_XML(independent_parameters_document);
       }
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


// void print(void) const method   

/// Prints to the screen the members of a neural network object in a XML-type format.

void NeuralNetwork::print(void) const
{
   if(display)
   {
      std::cout << to_string();
   }
}


// void save(const std::string&) const method 

/// Saves to a XML file the members of a neural network object.
/// @param file_name Name of neural network XML file.

void NeuralNetwork::save(const std::string& file_name) const
{
   tinyxml2::XMLDocument* document = to_XML();

   document->SaveFile(file_name.c_str());

   delete document;
 }


// void save_parameters(const std::string&) const method 

/// Saves to a data file the parameters of a neural network object.
/// @param file_name Name of parameters data file.

void NeuralNetwork::save_parameters(const std::string& file_name) const
{
   std::ofstream file(file_name.c_str());

   if(!file.is_open())
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "void save_parameters(const std::string&) const method.\n"
             << "Cannot open parameters data file.\n";

	  throw std::logic_error(buffer.str());
   }

   const Vector<double> parameters = arrange_parameters();

   file << parameters << std::endl;

   // Close file

   file.close();
}


// void load(const std::string&) method

/// Loads from a XML file the members for this neural network object.
/// Please mind about the file format, which is specified in the User's Guide. 
/// @param file_name Name of neural network XML file.

void NeuralNetwork::load(const std::string& file_name)
{
    set_default();

   tinyxml2::XMLDocument document;

   if(document.LoadFile(file_name.c_str()))
   {
       std::ostringstream buffer;

      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "void load(const std::string&) method.\n"
             << "Cannot load XML file " << file_name << ".\n";

      throw std::logic_error(buffer.str());
   }

   from_XML(document);
}


// void load_parameters(const std::string&) method

/// Loads the multilayer perceptron parameters from a data file.
/// The format of this file is just a sequence of numbers. 
/// @param file_name Name of parameters data file. 

void NeuralNetwork::load_parameters(const std::string& file_name)
{
   std::ifstream file(file_name.c_str());

   if(!file.is_open())
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "void load_parameters(const std::string&) method.\n"
             << "Cannot open parameters data file.\n";

	  throw std::logic_error(buffer.str());
   }

   const unsigned parameters_number = count_parameters_number();

   Vector<double> new_parameters(parameters_number);

   new_parameters.load(file_name);

   set_parameters(new_parameters);

   file.close();
}


// std::string write_expression(void) const method

/// @todo

std::string NeuralNetwork::write_expression(void) const
{
   std::ostringstream buffer;

   #ifndef NDEBUG 

   if(!inputs_pointer)
   {
      buffer.str("");

      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "std::string write_expression(void) const method.\n"
             << "Pointer to inputs is NULL.\n";

	  throw std::logic_error(buffer.str());
   }

   if(!multilayer_perceptron_pointer)
   {
      buffer.str("");

      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "std::string write_expression(void) const method.\n"
             << "Pointer to multilayer perceptron is NULL.\n";

	  throw std::logic_error(buffer.str());
   }

   if(!outputs_pointer)
   {
      buffer.str("");

      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "std::string write_expression(void) const method.\n"
             << "Pointer to outputs is NULL.\n";

      throw std::logic_error(buffer.str());
   }

   #endif

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();
   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   const Vector<std::string> inputs_name = inputs_pointer->arrange_names();
   const Vector<std::string> outputs_name = outputs_pointer->arrange_names();

   // Scaled inputs

   Vector<std::string> scaled_inputs_name(inputs_number);

   for(unsigned i = 0; i < inputs_number; i++)
   {
      buffer.str("");

      buffer << "scaled_" << inputs_name[i];
       
      scaled_inputs_name[i] = buffer.str();
   }      

   // Scaled outputs

   Vector<std::string> scaled_outputs_name(outputs_number);

   for(unsigned i = 0; i < outputs_number; i++)
   {
      buffer.str("");

      buffer << "scaled_" << outputs_name[i];
       
      scaled_outputs_name[i] = buffer.str();
   }      

   // Non probabilistic outputs

   Vector<std::string> non_probabilistic_outputs_name(outputs_number);

   for(unsigned i = 0; i < outputs_number; i++)
   {
      buffer.str("");

      buffer << "non_probabilistic_" << outputs_name[i];
       
      non_probabilistic_outputs_name[i] = buffer.str();
   }      

   buffer.str("");

   // Scaling layer

   if(scaling_layer_pointer)
   {
      buffer << scaling_layer_pointer->write_expression(inputs_name, scaled_inputs_name);
   }

   // Multilayer perceptron 

   if(multilayer_perceptron_pointer)
   {
      if(scaling_layer_pointer && unscaling_layer_pointer)
      {
         buffer << multilayer_perceptron_pointer->write_expression(scaled_inputs_name, scaled_outputs_name);      
      }
      else if(scaling_layer_pointer && probabilistic_layer_pointer)
      {
         buffer << multilayer_perceptron_pointer->write_expression(scaled_inputs_name, non_probabilistic_outputs_name);
      }
      else
      {
         buffer << multilayer_perceptron_pointer->write_expression(inputs_name, outputs_name);      
      }
   }

   // Outputs unscaling

   if(unscaling_layer_pointer)
   {
      buffer << unscaling_layer_pointer->write_expression(scaled_outputs_name, outputs_name);
   }

   // Probabilistic layer

   if(probabilistic_layer_pointer)
   {
      buffer << probabilistic_layer_pointer->write_expression(non_probabilistic_outputs_name, outputs_name);
   }

   // Conditions layer

//   if(conditions_layer_pointer)
//   {
//      buffer << conditions_layer_pointer->write_expression(inputs_name, outputs_name);   
//   }

   std::string expression = buffer.str();

   size_t pos;

   std::string search;
   std::string replace;

   pos = 0;

   search = "--";
   replace = "+";

   while((pos = expression.find(search, pos)) != std::string::npos)
   {
          expression.replace(pos, search.length(), replace);
          pos += replace.length();
   }

   pos = 0;

   search = "+-";
   replace = "-";

   while((pos = expression.find(search, pos)) != std::string::npos)
   {
          expression.replace(pos, search.length(), replace);
          pos += replace.length();
   }

   return(expression);
}


// void save_expression(const std::string&) method

/// Saves the mathematical expression represented by the neural network to a text file.
/// @param file_name Name of expression text file. 

void NeuralNetwork::save_expression(const std::string& file_name)
{
   std::ofstream file(file_name.c_str());

   if(!file.is_open())
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "void  save_expression(const std::string&) method.\n"
             << "Cannot open expression text file.\n";

	  throw std::logic_error(buffer.str());
   }

   file << write_expression();

   file.close();
}


// void save_data(const std::string&) const method

/// Saves a set of input-output values from the neural network to a data file.
/// @param file_name Name of data file. 

void NeuralNetwork::save_data(const std::string& file_name) const
{
   #ifndef NDEBUG 

   std::ostringstream buffer;

   if(!multilayer_perceptron_pointer)
   {
      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "void save_data(const std::string&) const method.\n"
             << "Pointer to multilayer perceptron is NULL.\n";

	  throw std::logic_error(buffer.str());
   }

   #endif

   const unsigned inputs_number = multilayer_perceptron_pointer->get_inputs_number();

   #ifndef NDEBUG 

   if(inputs_number != 1)
   {
      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "void save_data(const std::string&) const method.\n"
             << "Number of inputs is not 1.\n";

	  throw std::logic_error(buffer.str());
   }

   #endif

   #ifndef NDEBUG 

   if(!scaling_layer_pointer)
   {
      buffer << "OpenNN Exception: NeuralNetwork class.\n"
             << "void save_data(const std::string&) const method.\n"
             << "Pointer to scaling layer is NULL.\n";

	  throw std::logic_error(buffer.str());
   }

   #endif

   const unsigned outputs_number = multilayer_perceptron_pointer->get_outputs_number();

   const unsigned variables_number = inputs_number + outputs_number;

   const Vector< Statistics<double> > scaling_layer_statistics = scaling_layer_pointer->get_statistics();
//   const Vector< Statistics<double> > unscaling_layer_statistics = unscaling_layer_pointer->get_statistics();

//   const Vector< Statistics<double> > inputs_minimums = scaling_layer_pointer->get_minimums();
//   const Vector<double> inputs_maximums = scaling_layer_pointer->get_maximums();
 
   const unsigned points_number = 101;

   Matrix<double> data(points_number, variables_number);

   Vector<double> inputs(inputs_number);
   Vector<double> outputs(outputs_number);
   Vector<double> row(variables_number);

   Vector<double> increments(inputs_number);

   for(unsigned i = 0; i < inputs_number; i++)
   {
       inputs[i] = scaling_layer_statistics[i].minimum;
       increments[i] = (scaling_layer_statistics[i].maximum - scaling_layer_statistics[i].minimum)/(double)(points_number-1.0);
   }

   for(unsigned i = 0; i < points_number; i++)
   {      
      outputs = calculate_outputs(inputs);

      row = inputs.assemble(outputs);

      data.set_row(i, row);

      inputs += increments;
   }

   data.save(file_name);

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
