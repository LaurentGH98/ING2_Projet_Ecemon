#ifndef DEFENSE_H_INCLUDED
#define DEFENSE_H_INCLUDED

class Defense
{
private :
    std::string m_nom;
    std::string m_description;
    int m_pointsDeDefense;
    int m_pointsEnergieRecquis;
    std::string m_typeEnergieRecquis;

public:
    ///constructeur et destructeur
    Defense(std::string nom, std::string description, int pointsDeDefense, int pointsEnergieRecquis, std::string typeEnergieRecquis);
    ~Defense();

    ///getters
    std::string getNom() const;
    std::string getDescription() const;
    int getPointsDeDefense() const;
    int getPointsEnergieRecquis() const;
    std::string getTypeEnergieRecquis() const;

    ///setters
    void setNom(std::string nom);
    void setDescription(std::string description);
    void setPointsDeDefense(int pointsDeDefense);
    void setPointsEnergieRecquis(int pointsEnergieRecquis);
    void setTypeEnergieRecquis(std::string typeEnergieRecquis);

    ///méthodes
};

#endif // DEFENSE_H_INCLUDED
