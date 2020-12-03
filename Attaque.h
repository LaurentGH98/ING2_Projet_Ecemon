#ifndef ATTAQUE_H_INCLUDED
#define ATTAQUE_H_INCLUDED

class Attaque
{
private :
    std::string m_nom;
    std::string m_description;
    int m_pointsDeDegats;
    int m_pointsEnergieRecquis;
    std::string m_typeEnergieRecquis;
public:
    ///constructeur et destructeur
    Attaque(std::string nom, std::string description, int pointsDeDegats, int pointsEnergieRecquis, std::string typeEnergieRecquis);
    ~Attaque();

    ///getters
    std::string getNom() const;
    std::string getDescription() const;
    int getPointsDeDegats() const;
    int getPointsEnergieRecquis() const;
    std::string getTypeEnergieRecquis() const;

    ///setters
    void setNom(std::string nom);
    void setDescription(std::string description);
    void setPointsDeDegats(int pointsDeDegats);
    void setPointsEnergieRecquis(int pointsEnergieRecquis);
    void setTypeEnergieRecquis(std::string typeEnergieRecquis);

    ///m�thodes

};

#endif // ATTAQUE_H_INCLUDED
