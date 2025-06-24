/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:56:19 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/18 18:31:44 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

void testBasicSerialization()
{
    std::cout << "=== Test 1: Basic Serialization ===" << std::endl;
    
    Data *dataT = new Data();
    dataT->name = "test";
    dataT->value = 42;

    std::cout << "Data before serialization: name:" << dataT->name << " value:" << dataT->value << std::endl;

    uintptr_t dataSerialized = Serializer::serialize(dataT);
    std::cout << "Data after serialization: " << dataSerialized << std::endl;

    Data *dataDeserialized = Serializer::deserialize(dataSerialized);
    std::cout << "Data after deserialization name:" << dataDeserialized->name << " Value = " << dataDeserialized->value << std::endl;
    std::cout << "Pointers match: " << (dataT == dataDeserialized ? "Yes" : "No") << std::endl;
    
    delete dataT;
    std::cout << std::endl;
}

void testNullPointer()
{
    std::cout << "=== Test 2: NULL Pointer Serialization ===" << std::endl;
    
    Data *nullPtr = NULL;
    std::cout << "Original pointer: " << nullPtr << std::endl;
    
    uintptr_t serializedNull = Serializer::serialize(nullPtr);
    std::cout << "Serialized NULL: " << serializedNull << std::endl;
    
    Data *deserializedNull = Serializer::deserialize(serializedNull);
    std::cout << "Deserialized pointer: " << deserializedNull << std::endl;
    std::cout << "NULL pointers match: " << (nullPtr == deserializedNull ? "Yes" : "No") << std::endl;
    
    std::cout << std::endl;
}

void testMultipleObjects()
{
    std::cout << "=== Test 3: Multiple Objects ===" << std::endl;
    
    Data *data1 = new Data();
    data1->name = "Object1";
    data1->value = 100;
    
    Data *data2 = new Data();
    data2->name = "Object2";
    data2->value = 200;
    
    Data *data3 = new Data();
    data3->name = "Object3";
    data3->value = 300;
    
    std::cout << "Original pointers: data1=" << data1 << " data2=" << data2 << " data3=" << data3 << std::endl;
    
    // Serialize all objects
    uintptr_t ser1 = Serializer::serialize(data1);
    uintptr_t ser2 = Serializer::serialize(data2);
    uintptr_t ser3 = Serializer::serialize(data3);
    
    std::cout << "Serialized values: " << ser1 << " " << ser2 << " " << ser3 << std::endl;
    
    // Deserialize in different order
    Data *deser3 = Serializer::deserialize(ser3);
    Data *deser1 = Serializer::deserialize(ser1);
    Data *deser2 = Serializer::deserialize(ser2);
    
    std::cout << "Deserialized pointers: deser1=" << deser1 << " deser2=" << deser2 << " deser3=" << deser3 << std::endl;
    
    // Verify data integrity
    std::cout << "Data1 match: " << (data1 == deser1 ? "Yes" : "No") << " Values: " << deser1->name << "=" << deser1->value << std::endl;
    std::cout << "Data2 match: " << (data2 == deser2 ? "Yes" : "No") << " Values: " << deser2->name << "=" << deser2->value << std::endl;
    std::cout << "Data3 match: " << (data3 == deser3 ? "Yes" : "No") << " Values: " << deser3->name << "=" << deser3->value << std::endl;
    
    delete data1;
    delete data2;
    delete data3;
    std::cout << std::endl;
}

void testRoundTripSerialization()
{
    std::cout << "=== Test 4: Round-trip Serialization ===" << std::endl;
    
    Data *original = new Data();
    original->name = "RoundTrip";
    original->value = 999;
    
    std::cout << "Original: " << original << " name=" << original->name << " value=" << original->value << std::endl;
    
    // Multiple round trips
    uintptr_t ser1 = Serializer::serialize(original);
    Data *deser1 = Serializer::deserialize(ser1);
    
    uintptr_t ser2 = Serializer::serialize(deser1);
    Data *deser2 = Serializer::deserialize(ser2);
    
    uintptr_t ser3 = Serializer::serialize(deser2);
    Data *deser3 = Serializer::deserialize(ser3);
    
    std::cout << "After 3 round trips: " << deser3 << " name=" << deser3->name << " value=" << deser3->value << std::endl;
    std::cout << "All pointers equal: " << (original == deser1 && deser1 == deser2 && deser2 == deser3 ? "Yes" : "No") << std::endl;
    
    delete original;
    std::cout << std::endl;
}

void testDifferentDataValues()
{
    std::cout << "=== Test 5: Different Data Values ===" << std::endl;
    
    // Test with empty strings
    Data *emptyData = new Data();
    emptyData->name = "";
    emptyData->value = 0;
    
    uintptr_t serEmpty = Serializer::serialize(emptyData);
    Data *deserEmpty = Serializer::deserialize(serEmpty);
    std::cout << "Empty data test: '" << deserEmpty->name << "' value=" << deserEmpty->value << " match=" << (emptyData == deserEmpty ? "Yes" : "No") << std::endl;
    
    // Test with special characters
    Data *specialData = new Data();
    specialData->name = "Special!@#$%^&*()";
    specialData->value = -42;  // Fixed: use int instead of double
    
    uintptr_t serSpecial = Serializer::serialize(specialData);
    Data *deserSpecial = Serializer::deserialize(serSpecial);
    std::cout << "Special chars test: '" << deserSpecial->name << "' value=" << deserSpecial->value << " match=" << (specialData == deserSpecial ? "Yes" : "No") << std::endl;
    
    // Test with very large values
    Data *largeData = new Data();
    largeData->name = "VeryLongStringWithLotsOfCharactersToTestMemoryHandling";
    largeData->value = 999999;  // Fixed: use int instead of double
    
    uintptr_t serLarge = Serializer::serialize(largeData);
    Data *deserLarge = Serializer::deserialize(serLarge);
    std::cout << "Large data test: '" << deserLarge->name << "' value=" << deserLarge->value << " match=" << (largeData == deserLarge ? "Yes" : "No") << std::endl;
    
    delete emptyData;
    delete specialData;
    delete largeData;
    std::cout << std::endl;
}

int main()
{
    std::cout << "========== SERIALIZER COMPREHENSIVE TESTS ==========" << std::endl << std::endl;
    
    // Run all tests
    testBasicSerialization();
    testNullPointer();
    testMultipleObjects();
    testRoundTripSerialization();
    testDifferentDataValues();
    
    std::cout << "========== ALL TESTS COMPLETED ==========" << std::endl;
    
    return 0;
}