## TLB Measurement

[`measure.cpp`](./measure.cpp) measures memory latency with 2^n pages. The CPU's TLB caches the translations needed to access those pages.

So if the program touches more pages than the TLB can hold, accesses then may take longer. Sudden increases in our timed outputs can suggest this, but cache effects can also technically cause increase, as well as other factors like context switches etc.