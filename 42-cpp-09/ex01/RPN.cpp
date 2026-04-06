/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:18:06 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:54 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

RPN::RPN() {}
RPN::~RPN() {}

static bool isOperator(const std::string &tok) {
	return tok == "+" || tok == "-" || tok == "*" || tok == "/";
}

static double applyOp(double a, double b, const std::string &op) {
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/") {
		if (b == 0.0) throw std::runtime_error("division by zero");
		return a / b;
	}
	throw std::runtime_error("invalid operator");
}

double RPN::evaluate(const std::string &expr) const {
	std::stack<double> st;
	std::stringstream ss(expr);
	std::string token;
	while (ss >> token) {
		if (isOperator(token)) {
			if (st.size() < 2) throw std::runtime_error("invalid expression");
			double b = st.top(); st.pop();
			double a = st.top(); st.pop();
			st.push(applyOp(a, b, token));
		} else {
			char *end;
			double val = strtod(token.c_str(), &end);
			if (*end != '\0') throw std::runtime_error("invalid token");
			st.push(val);
		}
	}
	if (st.size() != 1) throw std::runtime_error("invalid expression");
	return st.top();
}
