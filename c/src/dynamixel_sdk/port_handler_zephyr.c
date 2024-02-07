#include "port_handler_zephyr.h"

#include <kernel.h>
#include <device.h>
#include <stdbool.h>
#include <string.h>
#include <drivers/uart.h>

#define DYNAMIXEL_BUS_NUMS CONFIG_DYNAMIXEL_BUS_NUMS

struct _port_context {
    const struct device* bus;
    bool is_open;
};

static struct _port_context context[DYNAMIXEL_BUS_NUMS];

int portHandlerZephyr(const char *port_name)
{
    /* check exist port context */
    for (int i = 0; i < DYNAMIXEL_BUS_NUMS; i ++)
    {
        struct _port_context* port = &context[i];
        if (!port->bus)
            continue;

        if (strcmp(port->bus->name, port_name) == 0)
            return i;
    }

    /* assign new port context */
    const struct device* bus = device_get_binding(port_name);
    if (bus == NULL || !device_is_ready(bus))
        return -1;

    for (int i = 0; i < DYNAMIXEL_BUS_NUMS; i ++)
    {
        struct _port_context* port = &context[i];
        if (port->bus == NULL)
        {
            port->bus = bus;
            return i;
        }
    }

    return -1;
}

uint8_t openPortZephyr(int port_num)
{
    if (port_num < 0 || port_num >= DYNAMIXEL_BUS_NUMS)
        return -1;

    struct _port_context* ctx = &context[port_num];
    if (!ctx->bus)
        return -1;

    ctx->is_open = true;

    return 0;
}

void closePortZephyr(int port_num)
{
    if (port_num < 0 || port_num >= DYNAMIXEL_BUS_NUMS)
        return;

    struct _port_context* ctx = &context[port_num];
    ctx->is_open = false;
}

void clearPortZephyr(int port_num)
{
}

void setPortNameZephyr(int port_num, const char *port_name)
{
    return 0;
}

char *getPortNameZephyr(int port_num)
{
    return 0;
}

uint8_t setBaudRateZephyr(int port_num, const int baudrate)
{
    return 0;
}

int getBaudRateZephyr(int port_num)
{
    return 0;
}

int getBytesAvailableZephyr(int port_num)
{
    return 0;
}

int readPortZephyr(int port_num, uint8_t *packet, int length)
{
    return 0;
}

int writePortZephyr(int port_num, uint8_t *packet, int length)
{
    return 0;
}

void setPacketTimeoutZephyr(int port_num, uint16_t packet_length)
{
    return 0;
}

void setPacketTimeoutMSecZephyr(int port_num, double msec)
{
    return 0;
}

uint8_t isPacketTimeoutZephyr(int port_num)
{
    return 0;
}

