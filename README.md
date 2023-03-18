# Messenger App
A messenger applictation that sends optionally encrypted messages from a source to a destination.

The app must receive a command specifying the desired source and destination option, and optionally the type of encryption.
Then, the app reads the message, encrypts it and sends it to the final destination.

Current available sources:
- Console
- File

Destinations:
- Console
- File
- TCP socket

Encryption types (can choose one or more):
- ROT13
- Uppercase
- Xor

This app uses the factory design pattern for creating the requested source, destination and encryption objects.
