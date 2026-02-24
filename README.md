# Safe
**Safe** is a runtime library that defines a safe context for C++.
It tracks every heap-allocated instance of types that inherit from `Safe::SafeContextBase` and offers recycling/repurpose mechanisms, using only C++ standard library.

## 📥 Download & Installation
Download the library package for your platform.
Extract the package to your project directory and specify the paths to the library's header files. Link to the library files (`.sll`,`.dll`, `.a` or `.so`) by adding to the dependency inputs. If you want to use the dynamic library, copy the library file(s) to the folder(s) of the output executable(s).


> [!NOTE]
On Windows, in order to avoid the confusion between the `.lib` files that go with `.dll` in dynamic libraries, `Safe` will use `.sll` as the file extension for static libraries. Linking to the static libraries with `.sll` extension is fine like linking to `.lib` files in other projects.


## 📖 Reference & Guide
See [Reference](Safe/Reference.md) to view API reference and [Guide](Safe/Guide.md) to view guide.


## 💡 Examples
```c++
#include <cstdlib>
#include <utility>

class Example : public Safe::SafeContextBase //or `class Example safe`
{
public:
	Example()
	{
		
	};
	Example(const Example& other) noexcept
	{
		
	};
	Example(Example&& other) noexcept
	{
		
	};
	~Example() override = default;


	Example& operator=(const Example& other) noexcept
	{
		return *this;
	};

	Example& operator=(Example&& other) noexcept
	{
		return *this;
	};
};

int main()
{
	Example* pointer = ::new Example();
	Example* anotherPointer = ::new Example();
	Example* pointerAlias = pointer;
	Safe::SafeContextBase::recycle(dynamic_cast<Safe::SafeContextBase*>(pointer)); // `pointer` is no longer meaningful after recycling.
	Example& repurposedReference = Safe::SafeContextBase::repurpose<Example>();

	return 0;
};
```

## ✍️ Authors
	Duc Nguyen (https://www.github.com/QuantumBoy1010/)


## 🛠️ Feedback & Error reports

This project is a result of ongoing research. If you encounter any issues, find a bug in the headers, or have suggestions for performance improvements, your feedback is highly valued!

* **GitHub Issues:** Please use the [Issues](https://github.com/QuantumBoy1010/Safe/issues) tab to report technical errors or bugs.
* **Email:** For detailed feedback or private inquiries, feel free to reach out to me directly at **workofduc@gmail.com**.
* **Feature Requests:** If you have a specific use case that the current runtime doesn't cover, I'd love to hear about it.
 

## 💖 Support the Project

If you find this runtime library useful for your research or hobby projects, consider supporting my work. Your sponsorship helps me dedicate more time to optimizing memory management research, fixing errors and keeping the engine up to date.

* **[Sponsor on GitHub](https://github.com/sponsors/duc18020319)**


## ⚖️ License
	This library project is licensed under the PolyForm Non-commercial License 1.0.0.
	Non-commercial/Educational Use: Free.
	Commercial Use: Prohibited without a separate commercial license.
	Please contact workofduc@gmail.com for pricing and licensing terms.
