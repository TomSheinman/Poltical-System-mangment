#pragma once

/// Exception classes, all we inherit from class InputError, inheritance so we can catch all of the error in one catch

class InputError : exception{
public:
    /**
     * How we handle the error the inherit exception classes will implement it as fit
     * it will send an appropriate error message for each error
     */
    virtual void Handle()const = 0;
};

class InvalidId : public InputError{
    void Handle()const override {cout << "Please enter valid id" << endl;}
};

class InvalidName : public InputError{
    void Handle()const override {cout << "Please enter valid name" << endl;}
};

class InvalidData : public InputError{
    void Handle()const override {cout << "Please enter valid details" << endl;}
};