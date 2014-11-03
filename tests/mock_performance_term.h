/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   M O C K   P E R F O R M A N C E   T E R M   C L A S S   H E A D E R                                        */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __MOCKPERFORMANCETERM_H__
#define __MOCKPERFORMANCETERM_H__


// OpenNN includes

#include "../source/opennn.h"


using namespace OpenNN;


class MockPerformanceTerm : public PerformanceTerm
{

public:

   // DEFAULT CONSTRUCTOR

   explicit MockPerformanceTerm(void);

   // GENERAL CONSTRUCTOR

   explicit MockPerformanceTerm(NeuralNetwork*);

   // DESTRUCTOR

   virtual ~MockPerformanceTerm(void); 

    // ENUMERATIONS

    enum Expression{SumSquaredParameters, OutputIntegral};

   // METHODS

    const Expression& get_expression(void) const;
    void set_expression(const Expression&);

    void set_default(void);

    // Sum squared parameters methods

    double calculate_sum_squared_parameters(void) const;
    Vector<double> calculate_sum_squared_parameters_gradient(void) const;
    Matrix<double> calculate_sum_squared_parameters_Hessian(void) const;

    Vector<double> calculate_sum_squared_parameters_terms(void) const;
    Matrix<double> calculate_sum_squared_parameters_terms_Jacobian(void) const;

    double calculate_sum_squared_parameters(const Vector<double>&) const;
    Vector<double> calculate_sum_squared_parameters_gradient(const Vector<double>&) const;
    Matrix<double> calculate_sum_squared_parameters_Hessian(const Vector<double>&) const;

   // Output integral methods

   double calculate_output_integral_integrand(const double&) const;
   double calculate_output_integral(void) const;
   
   Vector<double> calculate_output_integral_integrand_gradient(const double&) const;
   Vector<double> calculate_output_integral_gradient(void) const;

   Matrix<double> calculate_output_integral_integrand_Hessian(const double&) const;
   Matrix<double> calculate_output_integral_Hessian(void) const;

   double calculate_output_integral(const Vector<double>&) const;
   Vector<double> calculate_output_integral_gradient(const Vector<double>&) const;
   Matrix<double> calculate_output_integral_Hessian(const Vector<double>&) const;


   // Performance methods

   double calculate_performance(void) const;
   Vector<double> calculate_gradient(void) const;
   Matrix<double> calculate_Hessian(void) const;

   Vector<double> calculate_terms(void) const;
   Matrix<double> calculate_terms_Jacobian(void) const;

   double calculate_performance(const Vector<double>&) const;
   Vector<double> calculate_gradient(const Vector<double>&) const;
   Matrix<double> calculate_Hessian(const Vector<double>&) const;


private:

   Expression expression;

   NumericalIntegration numerical_integration;


};


#endif


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
