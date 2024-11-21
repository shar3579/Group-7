#include "stm32f4xx.h"

// Function Prototypes
void delay_ms(uint32_t ms);
void init_peripherals(void);
void start_buzzer(uint32_t frequency);
void stop_buzzer(void);
void trigger_ultrasonic(void);

volatile uint32_t echo_duration = 0;   // Variable for ultrasonic echo duration

int main(void)
{
    init_peripherals(); // Initialize all peripherals

    while (1)
    {
        // Additional logic for using echo_duration from ultrasonic sensor
        trigger_ultrasonic(); // Trigger ultrasonic sensor
        delay_ms(100);        // Main loop delay
    }
}

// EXTI2 Interrupt Handler (for ultrasonic echo on PA2)
void EXTI2_IRQHandler(void)
{
    static uint32_t start_time = 0;

    if (EXTI->PR & (1U << 2)) // Check if EXTI2 triggered
    {
        if (GPIOA->IDR & (1 << 2)) { // If echo signal goes high
            start_time = TIM3->CNT; // Capture start time
        } else { // If echo signal goes low
            echo_duration = TIM3->CNT - start_time; // Calculate duration
        }
        EXTI->PR |= (1U << 2); // Clear interrupt flag
    }
}

// Function to initialize peripherals and configure interrupts
void init_peripherals(void)
{
    // Enable GPIOA clock
    RCC->AHB1ENR |= (1U << 0);

    // Configure PA1 (Ultrasonic Trigger) as output
    GPIOA->MODER |= (1U << 2);

    // Configure PA2 (Ultrasonic Echo) as input
    GPIOA->MODER &= ~(0x3 << 4);

    // Configure interrupt for PA2 (EXTI2)
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; // Enable SYSCFG clock
    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI2_PA; // Map EXTI2 to PA2

    EXTI->IMR |= (1U << 2);   // Unmask EXTI2
    EXTI->RTSR |= (1U << 2);  // Rising edge trigger for PA2
    EXTI->FTSR |= (1U << 2);  // Falling edge trigger for PA2

    NVIC_EnableIRQ(EXTI2_IRQn); // Enable EXTI2 interrupt in NVIC

    // Enable TIM3 for ultrasonic measurement timing (prescaler set for 1 µs tick)
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    TIM3->PSC = 84 - 1; // Prescaler (1 MHz timer clock if APB1 is 84 MHz)
    TIM3->CR1 |= TIM_CR1_CEN; // Enable TIM3
}

// Function to start the buzzer with a specific frequency
void start_buzzer(uint32_t frequency)
{
    uint32_t period = 1000000 / frequency; // Period in microseconds
    TIM3->ARR = period - 1; // Set auto-reload register for period
    TIM3->CCR1 = period / 2; // 50% duty cycle for square wave
    TIM3->CR1 |= TIM_CR1_CEN; // Enable timer
}

// Function to stop the buzzer
void stop_buzzer(void)
{
    TIM3->CR1 &= ~TIM_CR1_CEN; // Disable timer
}

// Function to trigger the Ultrasonic Sensor (PA1)
void trigger_ultrasonic(void)
{
    GPIOA->ODR |= (1 << 1); // Set PA1 high
    delay_ms(10);           // Keep high for 10 microseconds
    GPIOA->ODR &= ~(1 << 1); // Set PA1 low
}

// Simple delay function (blocking delay)
void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms * 1000; i++) {
        __NOP();
    }
}
