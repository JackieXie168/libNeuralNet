/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   I N S T A N C E S   C L A S S                                                                              */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

// OpenNN includes

#include "instances.h"

namespace OpenNN
{


// DEFAULT CONSTRUCTOR

/// Default constructor. 
/// It creates a instances object with zero instances. 
/// It also initializes the rest of class members to their default values.

Instances::Instances(void)
{
   set();  
}


// INSTANCES NUMBER CONSTRUCTOR

/// Instances number constructor. 
/// It creates a data set object with a given number of instances.
/// It also initializes the rest of class members to their default values.
/// @param new_instances_number Number of instances in the data set.

Instances::Instances(const unsigned& new_instances_number)
{
    set(new_instances_number);
}


// XML CONSTRUCTOR

/// XML constructor. 
/// It creates a instances object by loading the object members from a TinyXML document.
/// @param instances_document XML document from the TinyXML library.

Instances::Instances(const tinyxml2::XMLDocument& instances_document)
{   
   set(instances_document);
}


// COPY CONSTRUCTOR

/// Copy constructor. 
/// It creates a copy of an existing instances object. 
/// @param other_instances Instances information object to be copied.

Instances::Instances(const Instances& other_instances)
{
   items = other_instances.items;

   display = other_instances.display;
}


// DESTRUCTOR

/// Destructor. 

Instances::~Instances(void)
{
}


// ASSIGNMENT OPERATOR

/// Assignment operator. 
/// It assigns to the current object the members of an existing instances object.
/// @param other_instances Instances information object to be assigned.

Instances& Instances::operator=(const Instances& other_instances)
{
   if(this != &other_instances) 
   {
      items = other_instances.items;
      display = other_instances.display;
   }

   return(*this);
}


// EQUAL TO OPERATOR

// bool operator == (const Instances&) const method

/// Equal to operator. 
/// It compares this object with another object of the same class. 
/// It returns true if the members of the two objects have the same values, and false otherwise.
/// @ param other_instances Instances information object to be compared with.

bool Instances::operator == (const Instances& other_instances) const
{
   if(/*items == other_instances.items
   &&*/ display == other_instances.display)
   {
      return(true);   
   }
   else
   {
      return(false);
   }
}


// METHODS

// static ScalingUnscalingMethod get_splitting_method(const std::string&) method

/// Returns a value of the splitting method enumeration from a string with that method.
/// @param splitting_method String with the method for splitting the instances.

Instances::SplittingMethod Instances::get_splitting_method(const std::string& splitting_method)
{
    if(splitting_method == "Sequential")
    {
        return(Sequential);
    }
    else if(splitting_method == "Random")
    {
        return(Random);
    }
    else
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: Instances class.\n"
               << "static SplittingMethod get_splitting_method(const std::string&).\n"
               << "Unknown splitting method: " << splitting_method << ".\n";

        throw std::logic_error(buffer.str());
    }
}


// Vector<Use> arrange_uses(void) const method

/// Returns the use of every instance (training, generalization, testing) in a vector. 

Vector<Instances::Use> Instances::arrange_uses(void) const
{
   const unsigned instances_number = get_instances_number();

   Vector<Use> uses(instances_number);

   for(unsigned i = 0; i < instances_number; i++)
   {
       uses[i] = items[i].use;
   }

   return(uses);
}


// Vector<std::string> write_uses(void) const method

/// Returns the use of every instance (training, generalization, testing) in a string vector. 

Vector<std::string> Instances::write_uses(void) const
{
   const unsigned instances_number = get_instances_number();

   const Vector<Use> uses = arrange_uses();

   Vector<std::string> uses_string(instances_number);

   for(unsigned i = 0; i < instances_number; i++)
   {
      if(uses[i] == Training)
	  {	  
	     uses_string[i] = "Training";    	     
	  }
      else if(uses[i] == Generalization)
	  {	  
	     uses_string[i] = "Generalization";    
	  }
      else if(uses[i] == Testing)
	  {	  
	     uses_string[i] = "Testing";    
	  }
      else if(uses[i] == Unused)
      {
         uses_string[i] = "Unused";
      }
      else
	  {
         std::ostringstream buffer;

         buffer << "OpenNN Exception Instances class.\n"
                << "Vector<std::string> write_uses(void) const method.\n"
                << "Unknown use.\n";
 
	     throw std::logic_error(buffer.str());
	  }
   }

   return(uses_string);
}


// Vector<std::string> write_abbreviated_uses(void) const method

/// Returns the use of every instance (training, generalization, testing) in a string vector.

Vector<std::string> Instances::write_abbreviated_uses(void) const
{
   const unsigned instances_number = get_instances_number();

   const Vector<Use> uses = arrange_uses();

   Vector<std::string> uses_string(instances_number);

   for(unsigned i = 0; i < instances_number; i++)
   {
      if(uses[i] == Training)
      {
         uses_string[i] = "Train.";
      }
      else if(uses[i] == Generalization)
      {
         uses_string[i] = "Gen.";
      }
      else if(uses[i] == Testing)
      {
         uses_string[i] = "Test.";
      }
      else if(uses[i] == Unused)
      {
         uses_string[i] = "Unused";
      }
      else
      {
         std::ostringstream buffer;

         buffer << "OpenNN Exception Instances class.\n"
                << "Vector<std::string> write_abbreviated_uses(void) const method.\n"
                << "Unknown use.\n";

         throw std::logic_error(buffer.str());
      }
   }

   return(uses_string);
}


// const Use& get_use(const unsigned&) const method

/// Returns the use of a single instance.
/// @param i Instance index.

const Instances::Use& Instances::get_use(const unsigned& i) const
{
    return(items[i].use);
}


// std::string write_use(const unsigned&) const method

/// Returns a string the use name of a single instance.
/// @param i Instance index.

std::string Instances::write_use(const unsigned& i) const
{
    if(items[i].use == Training)
    {
       return("Training");
    }
    else if(items[i].use == Generalization)
    {
       return("Generalization");
    }
    else if(items[i].use == Testing)
    {
       return("Testing");
    }
    else if(items[i].use == Unused)
    {
       return("Unused");
    }
    else
    {
       std::ostringstream buffer;

       buffer << "OpenNN Exception Instances class.\n"
              << "std::string write_use(const unsigned&) const method.\n"
              << "Unknown use.\n";

       throw std::logic_error(buffer.str());
    }
}


// unsigned count_unused_instances_number(void) const method

/// Returns the number of instances in the data set which will neither be used
/// for training, generalization or testing.

unsigned Instances::count_unused_instances_number(void) const
{
	const unsigned instances_number = get_instances_number();

	unsigned unused_instances_number = 0;

	for(unsigned i = 0; i < instances_number; i++)
	{
       if(items[i].use == Unused)
	   {
	      unused_instances_number++;
	   }
	}

	return(unused_instances_number);
}


// unsigned count_used_instances_number(void) const method

/// Returns the total number of training, generalization and testing instances,
/// i.e. those which are not "Unused".

unsigned Instances::count_used_instances_number(void) const
{
    const unsigned instances_number = get_instances_number();
    const unsigned unused_instances_number = count_unused_instances_number();

    return(instances_number - unused_instances_number);
}


// unsigned count_training_instances_number(void) const method

/// Returns the number of instances in the data set which will be used for training.

unsigned Instances::count_training_instances_number(void) const
{
	const unsigned instances_number = get_instances_number();

	unsigned training_instances_number = 0;

	for(unsigned i = 0; i < instances_number; i++)
	{
       if(items[i].use == Training)
	   {
	      training_instances_number++;
	   }
	}

	return(training_instances_number);
}


// unsigned count_generalization_instances_number(void) const method

/// Returns the number of instances in the data set which will be used for generalization.

unsigned Instances::count_generalization_instances_number(void) const
{
	const unsigned instances_number = get_instances_number();

	unsigned generalization_instances_number = 0;

	for(unsigned i = 0; i < instances_number; i++)
	{
       if(items[i].use == Generalization)
	   {
	      generalization_instances_number++;
	   }
	}

	return(generalization_instances_number);
}


// unsigned count_testing_instances_number(void) const method

/// Returns the number of instances in the data set which will be used for testing.

unsigned Instances::count_testing_instances_number(void) const
{
	const unsigned instances_number = get_instances_number();

	unsigned testing_instances_number = 0;

	for(unsigned i = 0; i < instances_number; i++)
	{
       if(items[i].use == Testing)
	   {
	      testing_instances_number++;
	   }
	}

	return(testing_instances_number);
}


// Vector<unsigned> count_uses(void) const method

/// Returns a vector with the number of training, generalization, testing
/// and unused instances.
/// The size of that vector is therefore four.

Vector<unsigned> Instances::count_uses(void) const
{
    Vector<unsigned> count(4, 0);

    const unsigned instances_number = get_instances_number();

    for(unsigned i = 0; i < instances_number; i++)
    {
        if(items[i].use == Training)
        {
           count[0]++;
        }
        else if(items[i].use == Generalization)
        {
           count[1]++;
        }
        else if(items[i].use == Testing)
        {
           count[2]++;
        }
        else
        {
           count[3]++;
        }
    }

    return(count);
}


// Vector<unsigned> arrange_training_indices(void) const method

/// Returns the indices of the instances which will be used for training.

Vector<unsigned> Instances::arrange_training_indices(void) const
{
   const unsigned instances_number = get_instances_number();

   const unsigned training_instances_number = count_training_instances_number();

   Vector<unsigned> training_indices(training_instances_number);

   unsigned count = 0;

   for(unsigned i = 0; i < instances_number; i++)
   {
      if(items[i].use == Training)
	  {
	     training_indices[count] = i;
		 count++;
	  }
   }

   return(training_indices);
}


// Vector<unsigned> arrange_generalization_indices(void) const method

/// Returns the indices of the instances which will be used for generalization.

Vector<unsigned> Instances::arrange_generalization_indices(void) const
{
   const unsigned instances_number = get_instances_number();

   const unsigned generalization_instances_number = count_generalization_instances_number();

   Vector<unsigned> generalization_indices(generalization_instances_number);

   unsigned count = 0;

   for(unsigned i = 0; i < instances_number; i++)
   {
      if(items[i].use == Generalization)
	  {
	     generalization_indices[count] = i;
		 count++;
	  }
   }

   return(generalization_indices);
}


// Vector<unsigned> arrange_testing_indices(void) const method

/// Returns the indices of the instances which will be used for testing.

Vector<unsigned> Instances::arrange_testing_indices(void) const
{
   const unsigned instances_number = get_instances_number();

   const unsigned testing_instances_number = count_testing_instances_number();

   Vector<unsigned> testing_indices(testing_instances_number);

   unsigned count = 0;

   for(unsigned i = 0; i < instances_number; i++)
   {
      if(items[i].use == Testing)
	  {
	     testing_indices[count] = i;
		 count++;
	  }
   }

   return(testing_indices);
}


// const bool& get_display(void) const method

/// Returns true if messages from this class can be displayed on the screen,
/// or false if messages from this class can't be displayed on the screen.

const bool& Instances::get_display(void) const
{
   return(display);   
}


// void set(void) method

/// Sets a instances object with zero instances. 

void Instances::set(void)
{
   set_instances_number(0);

   set_default();
}


// void set(const unsigned&) method

/// Sets a new number of instances in the instances object. 
/// All the instances are set for training. 
/// @param new_instances_number Number of instances.

void Instances::set(const unsigned& new_instances_number)
{
   set_instances_number(new_instances_number);

   set_default();
}


// void set(const tinyxml2::XMLDocument&) method

/// Sets the instances information members from a XML document.
/// @param instances_document Pointer to a TinyXML document containing the member data.

void Instances::set(const tinyxml2::XMLDocument& instances_document)
{
    set_default();

   from_XML(instances_document);
}


// void set_default(void) method

/// Sets the default values to this instances object:
/// <ul>
/// <li>display: true</li>
/// </ul>

void Instances::set_default(void)
{
    display = true;
}


// void set_uses(const Vector<Use>&) method

/// Sets new uses to all the instances from a single vector.
/// @param new_uses Vector of use structures.
/// The size must be equal to the number of instances.

void Instances::set_uses(const Vector<Instances::Use>& new_uses)
{
    const unsigned instances_number = get_instances_number();

   // Control sentence (if debug)

   #ifndef NDEBUG   

   const unsigned new_uses_size = new_uses.size();

   if(new_uses_size != instances_number)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Exception: Instances class.\n"
             << "void set_uses(const Vector<Use>&) method.\n"
             << "Size of uses (" << new_uses_size << ") must be equal to number of instances (" << instances_number << ").\n";

	  throw std::logic_error(buffer.str());
   }

   #endif

   for(unsigned i = 0; i < instances_number; i++)
   {
       items[i].use = new_uses[i];
   }
}


// void set_uses(const Vector<std::string>&) method 

/// Sets new uses to all the instances from a single vector of strings.
/// @param new_uses Vector of use strings.
/// Possible values for the elements are "Training", "Generalization", "Testing" and "Unused".
/// The size must be equal to the number of instances.

void Instances::set_uses(const Vector<std::string>& new_uses)
{
    const unsigned instances_number = get_instances_number();

    std::ostringstream buffer;

   // Control sentence (if debug)

   #ifndef NDEBUG   

   const unsigned new_uses_size = new_uses.size();

   if(new_uses_size != instances_number)
   {
      buffer << "OpenNN Exception: Instances class.\n"
             << "void set_uses(const Vector<std::string>&) method.\n"
             << "Size of uses (" << new_uses_size << ") must be equal to number of instances (" << instances_number << ").\n";

	  throw std::logic_error(buffer.str());
   }

   #endif

   for(unsigned i = 0; i < instances_number; i++)
   {   
      if(new_uses[i] == "Unused")
	  {	  
         items[i].use = Unused;
	  }
      else if(new_uses[i] == "Training")
	  {	  
         items[i].use = Training;
	  }
      else if(new_uses[i] == "Generalization")
	  {	  
         items[i].use = Generalization;
	  }
      else if(new_uses[i] == "Testing")
	  {	  
         items[i].use = Testing;
	  }
	  else
	  {
         buffer << "OpenNN Exception Instances class.\n"
                << "void set_uses(const Vector<std::string>&) method.\n"
                << "Unknown use.\n";
 
	     throw std::logic_error(buffer.str());
	  }
   }   
}


// void set_use(const Use&) method

/// Sets the use of a single instance.
/// @param i Index of instance.
/// @param new_use Use for that instance.

void Instances::set_use(const unsigned& i, const Use& new_use)
{
    items[i].use = new_use;
}


// void set_use(const unsigned&, const std::string&) method

/// Sets the use of a single instance from a string.
/// @param i Index of instance.
/// @param new_use String with the use name ("Training", "Generalization", "Testing" or "Unused")

void Instances::set_use(const unsigned& i, const std::string& new_use)
{
    if(new_use == "Training")
    {
       items[i].use = Training;
    }
    else if(new_use == "Generalization")
    {
       items[i].use = Generalization;
    }
    else if(new_use == "Testing")
    {
       items[i].use = Testing;
    }
    else if(new_use == "Unused")
    {
       items[i].use = Unused;
    }
    else
    {
       std::ostringstream buffer;

       buffer << "OpenNN Exception Instances class.\n"
              << "void set_use(const std::string&) method.\n"
              << "Unknown use: " << new_use << "\n";

       throw std::logic_error(buffer.str());
    }
}


// void set_training(void) method

/// Sets all the instances in the data set for training. 

void Instances::set_training(void)
{
   const unsigned instances_number = get_instances_number();

   for(unsigned i = 0; i < instances_number; i++)
   {
       items[i].use = Training;
   }
}


// void set_generalization(void) method

/// Sets all the instances in the data set for generalization. 

void Instances::set_generalization(void)
{
    const unsigned instances_number = get_instances_number();

    for(unsigned i = 0; i < instances_number; i++)
    {
        items[i].use = Generalization;
    }
}


// void set_testing(void) method

/// Sets all the instances in the data set for testing. 

void Instances::set_testing(void)
{
    const unsigned instances_number = get_instances_number();

    for(unsigned i = 0; i < instances_number; i++)
    {
        items[i].use = Testing;
    }
}


// void set_display(const bool&) method

/// Sets a new display value. 
/// If it is set to true messages from this class are to be displayed on the screen;
/// if it is set to false messages from this class are not to be displayed on the screen.
/// @param new_display Display value.

void Instances::set_display(const bool& new_display)
{
   display = new_display;
}


// void set_instances_number(const unsigned&) method

/// Sets a new number of instances in the data set. 
/// All instances are also set for training. 
/// @param new_instances_number Number of instances. 

void Instances::set_instances_number(const unsigned& new_instances_number)
{
   items.set(new_instances_number);

   split_instances();
}


// tinyxml2::XMLDocument* to_XML(void) const method

/// Serializes the instances object into a XML document of the TinyXML library. 
/// See the OpenNN manual for more information about the format of this document. 

tinyxml2::XMLDocument* Instances::to_XML(void) const
{
   tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument;

   std::ostringstream buffer;

   // Instances     

   tinyxml2::XMLElement* instances_element = document->NewElement("Instances");

   document->InsertFirstChild(instances_element);

   tinyxml2::XMLElement* element = NULL;
   tinyxml2::XMLText* text = NULL;

   const unsigned instances_number = get_instances_number();

   // Instances number
   {
      element = document->NewElement("InstancesNumber");
      instances_element->LinkEndChild(element);

      buffer.str("");
      buffer << instances_number;

      text = document->NewText(buffer.str().c_str());
      element->LinkEndChild(text);
   }

   for(unsigned i = 0; i < instances_number; i++)
   {
       element = document->NewElement("Item");
       element->SetAttribute("Index", i+1);
       instances_element->LinkEndChild(element);

       // Use

       tinyxml2::XMLElement* use_element = document->NewElement("Use");
       element->LinkEndChild(use_element);

       tinyxml2::XMLText* use_text = document->NewText(write_use(i).c_str());
       use_element->LinkEndChild(use_text);
   }

   // Display
   {
      element = document->NewElement("Display");
      instances_element->LinkEndChild(element);

      buffer.str("");
      buffer << display;

      text = document->NewText(buffer.str().c_str());
      element->LinkEndChild(text);
   }

   return(document);
}


// void from_XML(const tinyxml2::XMLDocument&) method

/// Deserializes a TinyXML document into this instances object.
/// @param instances_document XML document containing the member data.

void Instances::from_XML(const tinyxml2::XMLDocument& instances_document)
{
    std::ostringstream buffer;

    // Instances  element

   const tinyxml2::XMLElement* instances_element = instances_document.FirstChildElement("Instances");

   if(!instances_element)
   {
      buffer << "OpenNN Exception: Instances class.\n"
             << "void from_XML(const tinyxml2::XMLDocument&) method.\n"
             << "Pointer to instances information element is NULL.\n";

	  throw std::logic_error(buffer.str());   
   }

   // Instances number

   const tinyxml2::XMLElement* instances_number_element = instances_element->FirstChildElement("InstancesNumber");

   if(!instances_number_element)
   {
      buffer << "OpenNN Exception: Instances class.\n"
             << "void from_XML(const tinyxml2::XMLDocument&) method.\n"
             << "Pointer to instances number is NULL.\n";

      throw std::logic_error(buffer.str());
   }

   const unsigned instances_number = atoi(instances_number_element->GetText());

   set_instances_number(instances_number);

   if(instances_number <= 0)
   {
       return;
   }


   // Items

   unsigned index = 0;

   const tinyxml2::XMLElement* start_element = instances_number_element;

   for(unsigned i = 0; i < instances_number; i++)
   {
       const tinyxml2::XMLElement* item_element = start_element->NextSiblingElement("Item");
       start_element = item_element;

      if(!item_element)
      {
          buffer << "OpenNN Exception: Instances class.\n"
                 << "void from_XML(const tinyxml2::XMLElement*) method.\n"
                 << "Item " << i+1 << " is NULL.\n";

          throw std::logic_error(buffer.str());
      }

     item_element->QueryUnsignedAttribute("Index", &index);

     if(index != i+1)
     {
         buffer << "OpenNN Exception: Instances class.\n"
                << "void from_XML(const tinyxml2::XMLElement*) method.\n"
                << "Index " << index << " is not correct.\n";

         throw std::logic_error(buffer.str());
     }

     // Use

     const tinyxml2::XMLElement* use_element = item_element->FirstChildElement("Use");

     if(!use_element)
     {
        buffer << "OpenNN Exception: Instances class.\n"
               << "void from_XML(const tinyxml2::XMLElement*) method.\n"
               << "Pointer to use element is NULL.\n";

        throw std::logic_error(buffer.str());
     }

     if(use_element->GetText())
     {
        set_use(index-1, use_element->GetText());
     }
  }
}


// void split_random_indices(const double&, const double&, const double&) method

/// Creates new training, generalization and testing indices at random.
/// @param training_instances_ratio Ratio of training instances in the data set.
/// @param generalization_instances_ratio Ratio of generalization instances in the data set.
/// @param testing_instances_ratio Ratio of testing instances in the data set.

void Instances::split_random_indices
(const double& training_instances_ratio, const double& generalization_instances_ratio, const double& testing_instances_ratio)
{

   const unsigned used_instances_number = count_used_instances_number();

   const double total_ratio = training_instances_ratio + generalization_instances_ratio + testing_instances_ratio;

   // Get number of instances for training, generalization and testing

   const unsigned generalization_instances_number = (unsigned)(generalization_instances_ratio*used_instances_number/total_ratio);
   const unsigned testing_instances_number = (unsigned)(testing_instances_ratio*used_instances_number/total_ratio);
   const unsigned training_instances_number = used_instances_number - generalization_instances_number - testing_instances_number;

   const unsigned sum_instances_number = training_instances_number + generalization_instances_number + testing_instances_number;

   if(sum_instances_number != used_instances_number)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Warning: Instances class.\n" 
                << "void split_random_indices(const double&, const double&, const double&) method.\n"
                << "Sum of numbers of training, generalization and testing instances is not equal to number of used instances.\n";

      throw std::logic_error(buffer.str());
   }

   const unsigned instances_number = get_instances_number();

   Vector<int> indices(0, 1, instances_number-1);
   std::random_shuffle(indices.begin(), indices.end());

   unsigned i = 0;
   unsigned index;

   // Training

   unsigned count_training = 0;

   while(count_training != training_instances_number)
   {
      index = indices[i];

      if(items[index].use != Unused)
      {
        items[index].use = Training;
        count_training++;
      }

      i++;
   }

   // Generalization 

   unsigned count_generalization = 0;

   while(count_generalization != generalization_instances_number)
   {
      index = indices[i];

      if(items[index].use != Unused)
      {
        items[index].use = Generalization;
        count_generalization++;
      }

      i++;
   }

   // Testing 

   unsigned count_testing = 0;

   while(count_testing != testing_instances_number)
   {
      index = indices[i];

      if(items[index].use != Unused)
      {
            items[index].use = Testing;
            count_testing++;
      }

      i++;
   }
}


// void split_sequential_indices(const double&, const double&, const double&) method

/// Creates new training, generalization and testing indices with sequential indices.
/// @param training_instances_ratio Ratio of training instances in the data set.
/// @param generalization_instances_ratio Ratio of generalization instances in the data set.
/// @param testing_instances_ratio Ratio of testing instances in the data set.

void Instances::split_sequential_indices(const double& training_instances_ratio, const double& generalization_instances_ratio, const double& testing_instances_ratio)
{
   const unsigned used_instances_number = count_used_instances_number();

   const double total_ratio = training_instances_ratio + generalization_instances_ratio + testing_instances_ratio;

   // Get number of instances for training, generalization and testing

   const unsigned generalization_instances_number = (unsigned)(generalization_instances_ratio*used_instances_number/total_ratio);
   const unsigned testing_instances_number = (unsigned)(testing_instances_ratio*used_instances_number/total_ratio);
   const unsigned training_instances_number = used_instances_number - generalization_instances_number - testing_instances_number;

   const unsigned sum_instances_number = training_instances_number + generalization_instances_number + testing_instances_number;

   if(sum_instances_number != used_instances_number)
   {
      std::ostringstream buffer;

      buffer << "OpenNN Warning: Instances class.\n" 
             << "void split_random_indices(const double&, const double&, const double&) method.\n"
             << "Sum of numbers of training, generalization and testing instances is not equal to number of used instances.\n";
   
      throw std::logic_error(buffer.str());
   }

   unsigned i = 0;

   // Training

   unsigned count_training = 0;

   while(count_training != training_instances_number)
   {
      if(items[i].use != Unused)
      {
        items[i].use = Training;
        count_training++;
      }

      i++;
   }

   // Generalization

   unsigned count_generalization = 0;

   while(count_generalization != generalization_instances_number)
   {
      if(items[i].use != Unused)
      {
        items[i].use = Generalization;
        count_generalization++;
      }

      i++;
   }

   // Testing

   unsigned count_testing = 0;

   while(count_testing != testing_instances_number)
   {
      if(items[i].use != Unused)
      {
            items[i].use = Testing;
            count_testing++;
      }

      i++;
   }
}


// void split_instances(const SplittingMethod& splitting_method = Random, const double& training_ratio = 0.6, const double& generalization_ratio = 0.2, const double& testing_ratio = 0.2) method

/// Divides the instances into training, generalization and testing subsets.
/// @param splitting_method Instances splitting method (Sequential or Random, Random by default).
/// @param training_ratio Ratio of training instances (0.6 by default).
/// @param generalization_ratio Ratio of generalization instances (0.2 by default).
/// @param testing_ratio Ratio of testing instances (0.2 by default).

void Instances::split_instances(const SplittingMethod& splitting_method, const double& training_ratio, const double& generalization_ratio, const double& testing_ratio)
{

#ifndef NDEBUG

    std::ostringstream buffer;

    if(training_ratio < 0)
    {
        buffer << "OpenNN Exception: Instances class.\n"
               << "void split_instances(const SplittingMethod&, const double&, const double&, const double&) method.\n"
               << "Training ratio is lower than zero.\n";

        throw std::logic_error(buffer.str());
    }

    if(generalization_ratio < 0)
    {
        buffer << "OpenNN Exception: Instances class.\n"
               << "void split_instances(const SplittingMethod&, const double&, const double&, const double&) method.\n"
               << "Generalization ratio is lower than zero.\n";

        throw std::logic_error(buffer.str());
    }

    if(testing_ratio < 0)
    {
        buffer << "OpenNN Exception: Instances class.\n"
               << "void split_instances(const SplittingMethod&, const double&, const double&, const double&) method.\n"
               << "Testing ratio is lower than zero.\n";

        throw std::logic_error(buffer.str());
    }

    if(training_ratio == 0.0 && generalization_ratio == 0.0 && testing_ratio == 0.0)
    {
        buffer << "OpenNN Exception: Instances class.\n"
               << "void split_instances(const SplittingMethod&, const double&, const double&, const double&) method.\n"
               << "All training, generalization and testing ratios are zero.\n";

        throw std::logic_error(buffer.str());
    }

#endif

    switch(splitting_method)
    {
        case Instances::Sequential:
        {
             split_sequential_indices(training_ratio, generalization_ratio, testing_ratio);
        }
        break;

        case Instances::Random:
        {
             split_random_indices(training_ratio, generalization_ratio, testing_ratio);
        }
        break;

        default:
        {
           std::ostringstream buffer;

           buffer << "Neural Engine Exception: Instances class.\n"
                  << "void split_instances(const double&, const double&, const double&) method.\n"
                  << "Unknown splitting method.\n";

           throw std::logic_error(buffer.str());
        }
        break;
    }

}


// Vector<double> calculate_uses_percentage(void) const method

/// Returns the percentages of
/// unused, training, generalization and testing instances, respectively.

Vector<double> Instances::calculate_uses_percentage(void) const
{
    const unsigned instances_number = get_instances_number();

    Vector<double> uses_percentage(instances_number);

    const Vector<unsigned> uses_count = count_uses();

    for(unsigned i = 0; i < 4; i++)
    {
        uses_percentage[i] = 100.0*uses_count[i]/(double)instances_number;
    }

    return(uses_percentage);
}


// std::string to_string(void) const method

/// Returns a string representation of the current instances object. 

std::string Instances::to_string(void) const
{
   std::ostringstream buffer;

   buffer << "Instances information object\n"
	      << "Instances number: " << get_instances_number() << "\n"
	      << "Training instances number: " << count_training_instances_number() << "\n"
	      << "Generalization instances number: " << count_generalization_instances_number() << "\n"
	      << "Testing instances number: " << count_testing_instances_number() << "\n"
          << "Uses: " << write_uses() << "\n"
          << "Display: " << display << "\n";

   return(buffer.str());
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
