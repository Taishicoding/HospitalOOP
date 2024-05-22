"Staff will take the patients details to create a patient class with the interface that will then pair with a doctor to 
see them if they have to “availability” that doctor. Once they see the doctor, the doctor would then enter the symptoms 
to match with a medication. The medication data would populate a prescription the prescription would then be used by the pharmacy 
to find the medication and using the payment class take from the stock and record the payment."

Availability isn't tested by the program, and instead by staff, after accessing the 'appointment ID' then calling the patient after 
verifying a doctor's availability. 

There is simply a 'string' description that the doctor can access during the appointment; the doctor, more practically, bears the 
responsibility of prescribing medication, not the program. 

Payment function is implemented differently; instead of the Payment class, each appointment is assigned a price by staff, which is 
then added to a patient's account after an appointment. They can settle this payment through the patient mode.   

Each of these changes were observed as they were more practical, both for potential users and for programmers. 

