#include <SFML/Graphics.hpp>
#include "Generator.h"
#include "RepairStation.h"
#include "Field.h"
#include <iostream>
#include <unistd.h>

using namespace std;
int main() {
    int bounds[2]= {20, 20};
    int num1, num2;
    sf::Color colors[]= {sf::Color(230, 25, 75), sf::Color(60, 180, 75), sf::Color(255, 225, 25),
                         sf::Color(0, 130, 200), sf::Color(245, 130, 48), sf::Color(145, 30, 180),
                         sf::Color(70, 240, 240), sf::Color(240, 50, 230), sf::Color(210, 245, 60),
                         sf::Color(250, 190, 212), sf::Color(0, 128, 128), sf::Color(220, 190, 255),
                         sf::Color(170, 110, 40), sf::Color(255, 250, 200), sf::Color(128, 0, 0),
                         sf::Color(170, 255, 195), sf::Color(128, 128, 0), sf::Color(255, 215, 180),
                         sf::Color(0, 0, 128)};
    sf::VertexArray line(sf::LinesStrip, 2);
    Field f(600, 600, 2);
    cout<<"Enter the number of Generators: ";
    cin>>num1;
    cout<<endl<<"Enter the number of Repair stations: ";
    cin>>num2;
    f.random_fill(num1);
    f.k_means_init(num2);
    sf::RenderWindow window(sf::VideoMode(f.size_x()+bounds[0]*2, f.size_y()+bounds[1]*2), "Stations");
    sf::CircleShape gen_body;
    sf::RectangleShape station_body;
    sf::Color light_green(240,255,240);
    station_body.setOutlineThickness(3);
    station_body.setOutlineColor(sf::Color::Black);
    station_body.setSize(sf::Vector2f(20, 20));
    gen_body.setOutlineThickness(3);
    gen_body.setOutlineColor(sf::Color::Black);

    window.clear(sf::Color::White);
    for(int i=0; i<f.get_stations_count(); i++) {
        station_body.setPosition(f.get_station_pos_x(i)+bounds[0], f.get_stations_pos_y(i)+bounds[0]);
        station_body.setFillColor(sf::Color(150, 150, 150));
        window.draw(station_body);
    }
    for(int i=0; i<f.get_gen_count(); i++) {
        gen_body.setFillColor(sf::Color(150, 150, 150));
        gen_body.setPosition(f.get_gen_pos_x(i)+bounds[0], f.get_gen_pos_y(i)+bounds[1]);
        gen_body.setRadius(5*f.get_gen_lvl(i));
        window.draw(gen_body);
    }
    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        if(f.k_means_step()){
            window.clear(sf::Color::White);
            sf::sleep(sf::seconds(0.5));
        } else{
            window.clear(light_green);
        }


        for(int i=0; i<f.get_stations_count(); i++) {
            station_body.setPosition(f.get_station_pos_x(i)+bounds[0], f.get_stations_pos_y(i)+bounds[0]);
            station_body.setFillColor(colors[i%19]);
            for(int j=0; j<f.get_claster_size(i); j++) {
                gen_body.setFillColor(colors[i%19]);
                gen_body.setPosition(f.get_claster(i, j).X()+bounds[0], f.get_claster(i, j).Y()+bounds[1]);
                gen_body.setRadius(5*f.get_claster(i, j).LVL());
                line[0].position = sf::Vector2f(f.get_claster(i, j).X()+gen_body.getRadius()+bounds[0], f.get_claster(i, j).Y()+gen_body.getRadius()+bounds[1]);
                line[0].color  = colors[i%19];
                line[1].position = sf::Vector2f(f.get_station_pos_x(i)+bounds[0]+10, f.get_stations_pos_y(i)+bounds[1]+10);
                line[1].color = colors[i%19];
                window.draw(line);
                window.draw(gen_body);
            }
            window.draw(station_body);
        }
        window.display();


    }

    return 0;

}
