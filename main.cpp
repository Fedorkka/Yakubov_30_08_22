#include <SFML/Graphics.hpp>
#include "Generator.h"
#include "RepairStation.h"
#include "Field.h"
#include <iostream>
using namespace std;
int main() {
    int bounds[2]= {20, 20};
    int num1, num2;
    sf::Color colors[]= {sf::Color::Blue, sf::Color::Red,
                         sf::Color::Magenta, sf::Color::Green,
                         sf::Color::Yellow, sf::Color::Cyan
                        };

    Field f(600, 600, 2);
    cout<<"Enter the number of Generators: ";
    cin>>num1;
    cout<<endl<<"Enter the number of Repair stations: ";
    cin>>num2;
    f.random_fill(num1);
    f.k_means(num2);
    sf::RenderWindow window(sf::VideoMode(f.size_x()+bounds[0]*2, f.size_y()+bounds[1]*2), "Stations");
    sf::CircleShape gen_body;
    sf::RectangleShape station_body;
    station_body.setOutlineThickness(2);
    station_body.setOutlineColor(sf::Color::Black);
    station_body.setSize(sf::Vector2f(20, 20));
    gen_body.setOutlineThickness(2);
    gen_body.setOutlineColor(sf::Color::Black);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        for(int i=0; i<f.get_stations_count(); i++) {
            for(int j=0; j<f.get_claster_size(i); j++) {
                gen_body.setFillColor(colors[i%6]);
                station_body.setFillColor(colors[i%6]);
                gen_body.setPosition(f.get_claster(i, j).X()+bounds[0], f.get_claster(i, j).Y()+bounds[1]);
                gen_body.setRadius(5*f.get_claster(i, j).LVL());
                window.draw(gen_body);
            }
            station_body.setPosition(f.get_station_pos_x(i)-10, f.get_stations_pos_y(i)-10);
            window.draw(station_body);
        }

        window.display();
    }

    return 0;
}
