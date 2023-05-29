#ifndef I_COMPARABLE_HPP
# define I_COMPARABLE_HPP

template <class T>
class IComparable {
	public:

		virtual bool	operator==(T const &rhs) const = 0;
		virtual bool	operator<(T const &rhs) const = 0;

		virtual	~IComparable() {}

		friend bool	operator!=(T const &lhs, T const &rhs) {
			return !(lhs == rhs);
		}

		friend bool	operator<=(T const &lhs, T const &rhs) {
			return !(rhs < lhs);
		}

		friend bool	operator>(T const &lhs, T const &rhs) {
			return rhs < lhs;
		}

		friend bool	operator>=(T const &lhs, T const &rhs) {
			return !(lhs < rhs);
		}
};
#endif

