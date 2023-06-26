#include <vector>
#include <stdexcept>
#include <tuple>
#include <functional>
#include <optional>
#include <iostream>

typedef long long ll;

int main()
{
  enum class OP
  {
    ADD,
    ASSIGN
  };

  struct Node
  {
    typedef ll T;

    struct CalcData
    {
      CalcData() = default;
      CalcData(const T value) : m_sum(value) {}

      T m_sum;
    };

    struct ModifyOp
    {
      ModifyOp() = default;
      ModifyOp(OP op, const T value) : m_toAssign(op == OP::ASSIGN ? std::make_optional(value) : std::nullopt), m_toAdd(op == OP::ADD ? std::make_optional(value) : std::nullopt) {}

      std::optional<T> m_toAssign;
      std::optional<T> m_toAdd;
    };
  };

  struct MySegmentTree : public SegmentTree::SegmentTree<Node>
  {
    void UpdateModifyOp(ModifyOp& lhs, const ModifyOp& rhs) override
    {
      if (rhs.m_toAssign)
      {
        lhs.m_toAssign = rhs.m_toAssign;
        lhs.m_toAdd = rhs.m_toAdd;
      }
      else
      {
        if (lhs.m_toAdd)
        {
          *lhs.m_toAdd += *rhs.m_toAdd;
        }
        else
        {
          lhs.m_toAdd = rhs.m_toAdd;
        }
      }
    }

    void UpdateCalcData(CalcData& nodeCalcData, const ModifyOp& modifyOp, const size_t lx, const size_t rx) override
    {
      if (modifyOp.m_toAssign)
      {
        nodeCalcData.m_sum = *modifyOp.m_toAssign * (rx - lx);
      }
      if(modifyOp.m_toAdd)
      {
        nodeCalcData.m_sum += *modifyOp.m_toAdd * (rx - lx);
      }
    }

    CalcData CombineCalcData(const CalcData& leftChild, const CalcData& rightChild) override
    {
      CalcData res;
      res.m_sum = leftChild.m_sum + rightChild.m_sum;
      return res;
    }
  };
  
  int n, m;
  std::cin >> n >> m;
  
  MySegmentTree segTree;
  segTree.Build(n, 0);
  
  int op, l, r;
  ll value;
  
  for(int i = 0; i < m; ++i)
  {
      std::cin >> op;
      
      if(op == 1)
      {
          std::cin >> l >> r >> value;
          segTree.Modify(l, r, { OP::ASSIGN, value });
      } else if(op == 2)
      {
          std::cin >> l >> r >> value;
          segTree.Modify(l, r, { OP::ADD, value });
      } else
      {
          std::cin >> l >> r;
          std::cout << segTree.Calculate(l, r).m_sum << std::endl;
      }
  }
  
  return 0;
}