# Traffic Management System

## Overview

This project aims to create a comprehensive Traffic Management System implemented in Python. It includes functionalities for managing vehicle information, tracking traffic violations, handling incidents, and managing disputes.

## Class Design

### 1. Vehicle Information

#### Class Name: `Vehicle`

- **Attributes:**
  - Vehicle Number
  - Owner
  - Owner's Age
  - Gender
  - Address

- **Methods:**
  - `__init__(self, vehicle_number, owner, age, gender, address)`: Constructor to initialize attributes.
  - `display_info(self)`: Method to display vehicle information.

### 2. Traffic Violation Information

#### Class Name: `TrafficViolation`

- **Attributes:**
  - Location
  - Source of Report
  - Vehicle Number

- **Methods:**
  - `__init__(self, location, source, vehicle_number)`: Constructor to initialize attributes.
  - `display_info(self)`: Method to display violation information.

### 3. Address Identification

#### Class Name: `AddressIdentifier`

- **Methods:**
  - `identify_address(self, person_info)`: Method to identify probable addresses from a separate CSV file containing name, address, age, and gender.

### 4. Incident Record

#### Class Name: `IncidentRecord`

- **Attributes:**
  - Witnesses (list)
  - Violation Details
  - Response Text
  - Prior Record

- **Methods:**
  - `__init__(self, witnesses, violation_details, response_text, prior_record)`: Constructor to initialize attributes.
  - `display_info(self)`: Method to display incident record information.

## Usage

1. Clone the repository.
2. Run the main program to interact with the classes and perform various operations.
3. Provide CSV files containing vehicle information, violation reports, and personal records for testing.

## Example Usage

```python
# Example usage of the Vehicle class
vehicle1 = Vehicle("ABC123", "John Doe", 30, "Male", "123 Main St")
vehicle1.display_info()

# Example usage of the TrafficViolation class
violation1 = TrafficViolation("Intersection A", "Camera", "ABC123")
violation1.display_info()

# Example usage of the AddressIdentifier class
address_identifier = AddressIdentifier()
probable_addresses = address_identifier.identify_address(person_info)

# Example usage of the IncidentRecord class
incident1 = IncidentRecord(["Witness1", "Witness2"], "Speeding", "No comment", "No prior record")
incident1.display_info()
