# Task 9 note

The supplied two readings alone cannot distinguish a genuine 16-bit rollover from an incorrect decrease. This implementation assumes a decrease means one rollover. A production system should validate rollover using meter event metadata, elapsed time, or an explicit rollover flag. Test and explain this limitation in the report.
