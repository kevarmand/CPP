/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplacerAlgorithm.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:27:09 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 20:31:53 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_ALGORITHM_HPP
#define REPLACER_ALGORITHM_HPP

#include <string>
#include <cstddef>
#include <iosfwd> // std::ostream

class ReplacerAlgorithm {
public:
	ReplacerAlgorithm(const std::string& s1, const std::string& s2);
	void process(std::string& window, std::ostream& out, std::size_t keep_suffix);
	void flush(std::string& window, std::ostream& out);

private:
	std::string _s1;
	std::string _s2;
};

#endif // REPLACER_ALGORITHM_HPP