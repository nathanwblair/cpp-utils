#pragma once
#include <typeinfo>

#define combo_struct(left_struct, right_struct) \
	struct merged_struct_type \
	{ \
		left_struct left; \
		right_struct right; \
	};

// Merges a struct of a_type with a struct of b_type and gives the result in this->result
template <class a_type, class b_type>
class Merge
{
public:
	struct merged_struct_type;

	combo_struct(a_type, b_type)

	merged_struct_type result;


	Merge()
	{

	}

	Merge(a_type left, b_type right)
	{
		result.left = left;
		result.right = right;
	}
};

//
//// Stuff that refused to work:
//

//template <class a_type, class b_type, class... Args>
//class Merger
//{
//public:
//
////	typedef first<Args...>::type b_type;
////
////	struct merged_struct_type;
////
////	//combo_struct(a_type, first<Args...>::type)
////
////	struct merged_struct_type
////	{
////		a_type left;
////		first<Args...>::type right;
////	};
////
////	Merger(a_type left, b_type right)
////	{
////
////
////		result.left = left;
////		result.right = right;
////	}
//
//	Merger()
//	{
//
//	}
//
//
//	typedef DefaultMerger<a_type, b_type> current_merger_type;
//	typedef typename Merger<current_merger_type::merged_struct_type, Args...> actual_merger_type;
//	typedef typename actual_merger_type::merged_struct_type merged_struct_type;
//
////	typedef DefaultMerger<a_type, b_type> current_merger_type;
////	typedef Merger<DefaultMerger<a_type, b_type>::merged_struct_type, Args...> actual_merger_type;
////	typedef Merger<DefaultMerger<a_type, b_type>::merged_struct_type, Args...>::merged_struct_type merged_struct_type;
////
//	merged_struct_type result;
//
//	Merger(a_type a_struct, b_type b_struct, Args... structs)
//	{
//		result = actual_merger_type(current_merger_type(a_struct, b_struct).result, structs).result;
//	}
//};
//
//template <class a_type, class b_type, class c_type>
//class Merger
//{
//public:
//	struct merged_struct_type;
//
//
//	typedef DefaultMerger<a_type, b_type> current_merger_type;
//	typedef DefaultMerger<current_merger_type::merged_struct_type, c_type> actual_merger_type;
//	typedef actual_merger_type::merged_struct_type merged_struct_type;
//
////	typedef DefaultMerger<a_type, b_type> current_merger_type;
////	typedef Merger<DefaultMerger<a_type, b_type>::merged_struct_type, Args...> actual_merger_type;
////	typedef Merger<DefaultMerger<a_type, b_type>::merged_struct_type, Args...>::merged_struct_type merged_struct_type;
////
//	merged_struct_type result;
//
//	Merger(a_type a_struct, b_type b_struct, c_type c_struct)
//	{
//		result = actual_merger_type(current_merger_type(a_struct, b_struct).result, c_struct).result;
//	}
//};