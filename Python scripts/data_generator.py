#!/usr/bin/env python
# coding: utf-8

# In[2]:


import csv
import random


# In[3]:


# open the file in the write mode
file = open('input.csv', 'w')


# In[4]:


columns=["ID_order", "Release_time(sec)", "Order_provenience", "Order_dimension","Order_value","Type","Drink","Chips"]
order_proveniences = ["car", "person"]
menu_types = ["meat", "veggy", "chicken"]


# In[5]:


current_time = 0


# In[6]:


file.write(";".join(columns)+";;;\n")


# In[7]:


for i in range(100):
    order_id = 1000+i
    current_time = random.randint(30, 180)
    order_provenience = random.choice(order_proveniences)
    order_dim = random.randint(1,5)
    for j in range(order_dim):
        menu_type = random.choice(menu_types)
        drink = random.randint(0,1)
        chips = random.randint(0,1)
        file.write(str(order_id)+";"+str(current_time)+";"+str(order_provenience)+";"+str(order_dim)+";"+str(menu_type)+";"+str(drink)+";"+str(chips)+";;;\n")


# In[8]:


file.close()





