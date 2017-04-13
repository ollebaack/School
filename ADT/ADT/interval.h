//#pragma once
//
//#include <iostream>
//using namespace std;
//
//
//namespace Course
//{
//	namespace adt
//	{
//		template<class T>
//		class interval
//		{
//		private:
//			T upper;
//			T lower;
//		public:
//
//			interval(void)
//			{
//				lower = upper = 0;
//			}
//
//			interval(T mean, double procent)
//			{
//				lower = (T)(mean - mean * procent / 100); //L�tt att gl�mma (T), kr�vs d�  �r int
//				upper = (T)(mean + mean * procent / 100);
//			}
//
//			T mean()
//			{
//				return (lower + upper) / 2;
//			}
//
//			double relative_error()
//			{
//				return (upper - lower) / mean(); //Fungerar ej s� bra f�r int
//			}
//
//			void print_relative()
//			{
//				cout << "mean=" << mean() << ", relative error = " << relative_error() << endl;
//			}
//
//			friend interval<T> operator+(const interval<T> &lop, const interval<T> &rop)
//			{
//				interval<T> m;
//
//				m.upper = lop.upper + rop.upper;
//				m.lower = lop.lower + rop.lower;
//				return m;
//			}
//
//			friend interval<T> operator-(const interval<T> &lop, const interval<T> &rop)
//			{
//				interval<T> m;
//
//				m.upper = lop.upper - rop.upper;
//				m.lower = lop.lower - rop.lower;
//				return m;
//			}
//
//			friend interval<T> operator/(const interval<T> &lop, const interval<T> &rop)
//			{
//				interval<T> m;
//
//				if (rop.upper == 0 || rop.lower == 0)
//				{
//					cout << "Nope";
//				}
//				else
//				{
//					m.upper = lop.upper * (1 / rop.upper);
//					m.lower = lop.lower * (1 / rop.lower);
//					return m;
//				}
//				
//
//				
//			}
//
//			friend interval<T> operator*(const interval<T> &lop, const interval<T> &rop)
//			{
//				interval<T> m;
//
//				m.upper = max(max(lop.lower * rop.lower, lop.lower * rop.upper), max(lop.upper * rop.lower, lop.upper * rop.upper));
//				m.lower = min(min(lop.lower * rop.lower, lop.lower * rop.upper), min(lop.upper * rop.lower, lop.upper * rop.upper)); 
//				return m;
//			}
//
//			friend ostream& operator<<(ostream &out, const interval<T> &rop)
//			{
//				out << "[" << rop.lower << "," << rop.upper << "]";
//				return out;
//			}
//
//			~interval(void)
//			{
//			}
//		};
//	}
//}
//
//
